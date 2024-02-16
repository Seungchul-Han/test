#include "Factory.h"

// 생성자 함수 등록을 위한 템플릿 클래스 구현
template <typename T>
Factory::FactoryRegistration<T>::FactoryRegistration(const std::string& className) {
    Factory::instance().constructorMap[className] = []() {
		std::unique_ptr<T> b = std::make_unique<T>();
        return std::static_pointer_cast<Base>(b);
    };
}

// 객체 생성 함수
std::unique_ptr<Base> Factory::createObject(const std::string& className) {
    auto it = constructorMap.find(className);
    if (it != constructorMap.end()) {
        return it->second();
    }
    return nullptr;
}

// 싱글톤 패턴의 인스턴스 반환 함수 정의
Factory& Factory::instance() {
    static Factory instance;
    return instance;
}

// 생성자 함수 등록을 위한 템플릿 클래스의 특수화
template struct Factory::FactoryRegistration<Base>;
