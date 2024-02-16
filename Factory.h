#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <unordered_map>
#include <functional>
#include <memory>
#include <typeinfo>

// 기본 생성자를 가진 추상 클래스
class Base {
public:
    virtual void printInfo() const = 0;
    virtual ~Base() = default;
};

// 팩토리 클래스
class Factory {
public:
    // 싱글톤 패턴의 인스턴스 반환 함수
    static Factory& instance();

    // 생성 함수 등록을 위한 템플릿 클래스
    template <typename T>
    struct FactoryRegistration {
        explicit FactoryRegistration(const std::string& className);
    };

    // 객체 생성 함수
    std::unique_ptr<Base> createObject(const std::string& className);

private:
    // 생성 함수 맵
    std::unordered_map<std::string, std::function<std::unique_ptr<Base>()>> constructorMap;

    // 생성자와 소멸자는 private로 선언하여 싱글톤 패턴 적용
    Factory();
    ~Factory() = default;
};

#define REGISTER_FACTORY(className) \
    static Factory::FactoryRegistration<className> className##Registration(#className)

#endif // FACTORY_H
