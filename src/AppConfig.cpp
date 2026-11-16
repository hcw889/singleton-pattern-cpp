#include "AppConfig.h"

#include <iostream>

int AppConfig::createdCount = 0;

AppConfig::AppConfig() {
    createdCount++;
    std::cout << "  [AppConfig] 생성자 실행: 인스턴스를 새로 만들었습니다.\n";
}

AppConfig::~AppConfig() {
    std::cout << "  [AppConfig] 소멸자 실행: 프로그램이 끝나서 인스턴스를 정리했습니다.\n";
}

AppConfig& AppConfig::getInstance() {
    // 유일한 인스턴스를 보관하는 곳
    static AppConfig instance;

    // 두 번째 호출부터는 위 줄에서 새로 만들지 않고, 보관 중인 같은 객체를 돌려줍니다.
    return instance;
}

int AppConfig::getCreatedCount() {
    return createdCount;
}

// counter
void AppConfig::increment() {
    count++;
}

int AppConfig::getCount() const {
    return count;
}

// config
void AppConfig::setTheme(const std::string& newTheme) {
    theme = newTheme;
}

std::string AppConfig::getTheme() const {
    return theme;
}
