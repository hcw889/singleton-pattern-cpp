#pragma once

#include <string>

class AppConfig {
public:
    // 인스턴스를 얻는 유일한 방법
    static AppConfig& getInstance();

    // 복사 생성자와 복사 대입 연산자를 delete해서 복사도 막아버림
    AppConfig(const AppConfig&) = delete;
    AppConfig& operator=(const AppConfig&) = delete;

    ~AppConfig();

    static int getCreatedCount();

    //counter
    void increment();
    int getCount() const;

    // config
    void setTheme(const std::string& newTheme);
    std::string getTheme() const;

private:
    // 생성자를 private으로 막아버리기
    AppConfig();

    static int createdCount;

    int count = 0;
    std::string theme = "light";
};
