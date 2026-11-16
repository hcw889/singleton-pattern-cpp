// Singleton
// 1. 두 변수가 같은 객체를 가리키는지, 2. 상태가 공유되는지, 3. 클래스 밖에서 새로 만들 수 없는지
#include "AppConfig.h"

#include <iostream>
#include <string>
#include <type_traits>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    // Windows 콘솔은 기본 코드 페이지(CP949)로 글자를 해석해서 UTF-8 한글이 깨지므로, 출력 코드 페이지를 UTF-8로 바꿉니다. (이부분은 Claude에게 조언받아 진행했습니다.)
    SetConsoleOutputCP(CP_UTF8);
#endif
    std::cout << std::boolalpha;

    std::cout << "=== 1. 동일한 인스턴스인지 확인 ===\n";
    std::cout << "첫 번째 요청: AppConfig& config1 = AppConfig::getInstance();\n";
    AppConfig& config1 = AppConfig::getInstance();
    std::cout << "두 번째 요청: AppConfig& config2 = AppConfig::getInstance();\n";
    AppConfig& config2 = AppConfig::getInstance();

    std::cout << "&config1 : " << &config1 << "\n";
    std::cout << "&config2 : " << &config2 << "\n";
    std::cout << "&config1 == &config2 : " << (&config1 == &config2) << "\n";
    std::cout << "생성자 실행 횟수 : " << AppConfig::getCreatedCount() << "\n";

    std::string a = "light";
    std::string b = "light";
    std::cout << "\n(비교) 값이 같은 string 객체 두 개를 따로 만든 경우\n";
    std::cout << "a == b   : " << (a == b) << "\n";
    std::cout << "&a == &b : " << (&a == &b) << "\n";

    std::cout << "\n=== 2. 상태가 공유되는지 확인 ===\n";
    std::cout << "[변경 전] config2로 읽기 -> count: " << config2.getCount()
              << ", theme: " << config2.getTheme() << "\n";

    config1.increment();
    config1.increment();
    config1.increment();
    config1.setTheme("dark");
    std::cout << "[변경] config1.increment() 3번, config1.setTheme(\"dark\")\n";

    std::cout << "[변경 후] config2로 읽기 -> count: " << config2.getCount()
              << ", theme: " << config2.getTheme() << "\n";

    std::cout << "\n=== 3. 클래스 밖에서 새 인스턴스를 만들 수 없는지 확인 ===\n";
    // AppConfig config3;
    // AppConfig config4 = AppConfig::getInstance();
    // 위 두 줄의 주석을 풀면 컴파일 오류가 나서 실행 파일이 만들어지지 않습니다. (README 참고)

    // <type_traits>의 검사 도구로, 클래스 밖에서 위처럼 만들 수 있는지를 컴파일할 때 확인한 결과를 출력합니다.
    std::cout << "기본 생성 (AppConfig config3;) 가능? "
              << std::is_default_constructible_v<AppConfig> << "\n";
    std::cout << "복사 생성 (AppConfig config4 = AppConfig::getInstance();) 가능? "
              << std::is_copy_constructible_v<AppConfig> << "\n";

    // main이 끝나면 프로그램 종료 단계에서 static 지역 변수 instance의 소멸자가 한 번 실행됩니다.
    std::cout << "\nmain 함수 끝\n";
    return 0;
}
