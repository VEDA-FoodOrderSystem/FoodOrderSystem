# Quosk

VEDA 1기 B반 C++ 미니 프로젝트

개발 기간: 2024.08.01 ~ 2024.08.31

### 팀원 소개

---

| 김나형 | 윤혜경 |
| --- | --- |
| ![ㄱㄴㅎ](https://github.com/user-attachments/assets/2d4c14bd-b8d1-45cb-a2db-2d0cec71a620) | ![ㅇㅎㄱ](https://github.com/user-attachments/assets/be47e77b-cb46-4f6a-b13a-2cce6bedb255) |
| :@hyungee: | :@hyetae: |

### 프로젝트 소개

---

C++ STL 중 하나인 Queue와 Kiosk를 결합한 Quosk는 음식을 주문할 수 있는 키오스크의 기능을 C++로 구현하는 데에 목적을 두고 있습니다. 이때 객체 지향 설계 기법 중 하나인 책임 중심의 설계를 통해 각각의 객체가 명확한 역할과 책임을 가지게 해 유지보수와 확장을 용이하게 하고자 했습니다. 구체적인 역할과 책임은 다음과 같습니다.

1. 가게는 고객, 메뉴, 주문, 후기의 정보와 그들의 상호작용을 관리한다.
2. 가게는 메뉴와 주문의 CRUD를 제공하고, 고객의 정보와 후기를 수집한다.
3. 고객은 주문과 후기를 생성한다.

### 스택

---

**환경**

<img src="https://img.shields.io/badge/cmake-064F8C?style=for-the-badge&logo=cmake&logoColor=white">

<img src="https://img.shields.io/badge/git-F05032?style=for-the-badge&logo=git&logoColor=white">

<img src="https://img.shields.io/badge/github-181717?style=for-the-badge&logo=github&logoColor=white">

**개발**

<img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white">

**소통**

<img src="https://img.shields.io/badge/Slack-4A154B?style=for-the-badge&logo=slack&logoColor=FF007F">

<img src="https://img.shields.io/badge/Notion-000000?style=for-the-badge&logo=notion&logoColor=white">

**테스트**

<img src="https://img.shields.io/badge/Google-test-brightblue?style=for-the-badge&labelColor=brightgreen&logo=google">

### 기능

---

### ▶️ 메뉴 등록

| 이름 | 메뉴 등록 |
| --- | --- |
| ID | 1 |
| 설명 | 가게의 메뉴를 주문 프로그램에 등록하는 기능 |
| Actor | Manager |
| MainFlow | 1) 관리자 모드를 선택한다.<br>2) 메뉴 관리 모드에서 메뉴 등록을 선택한다.<br>3) 등록할 메뉴의 이름과 가격을 입력한다.<br>4) 메뉴를 생성하고, 메뉴 리스트에 추가한다.<br>5) 등록된 메뉴의 정보를 출력한다. |
| Alternative Flow |  |

[📑 기능 명세서 및 클래스 다이어그램 보러 가기](https://www.notion.so/7f9bd519db7343bea651d738657c3f4e?pvs=21)

### 규칙

---

**Branch Strategy** : trunck-based 전략

`main branch` : 주요 개발 branch

`feature branch`: 각자 개발 branch

- 순서에 해당하는 branch 생성 후 작업
    - ex) `/feature#num`
- 해당 branch 작업 완료 후 push
    - 본인이 충돌 해결후 main에 merge
- 구조
    
    ```
    - main
    ├── feature#1 : main, customer, menu 기능 추가
    ├── feature#2 : Order, review 기능 추가
    ├── feature#3 : 테스트 전 코드 리팩토링
    ├── feature#4 : 단위 테스트 코드 작성
    └── feature#5 : 오류 수정
    ```
    

**Commit Convention**

`ex) Feat/explain`

```
- Feat : 새로운 기능 추가
- Fix : 버그, 오류 해결
- Refactor: 기능 추가 없는 코드 수정
- Test : 테스트 추가
- Del : 코드 삭제
- Docs : 문서 수정
- Merge : 브랜치를 merge하는 경우
```

### 디렉터리 구조

---

```
.
├── Debug ...
├── foodOrderProgram
│   ├── -p
│   ├── CMakeLists.txt
│   ├── Customer.cpp
│   ├── Customer.h
│   ├── CustomerManager.cpp
│   ├── CustomerManager.h
│   ├── Debug ...
│   ├── FoodOrderSystem.cpp
│   ├── FoodOrderSystem.h
│   ├── Menu.cpp
│   ├── Menu.h
│   ├── MenuManager.cpp
│   ├── MenuManager.h
│   ├── Order.cpp
│   ├── Order.h
│   ├── OrderManager.cpp
│   ├── OrderManager.h
│   ├── Review.cpp
│   ├── Review.h
│   ├── ReviewManager.cpp
│   ├── ReviewManager.h
│   ├── cmake-build-debug ...
│   ├── foodOrderProgram.vcxproj
│   ├── foodOrderProgram.vcxproj.filters
│   ├── foodOrderProgram.vcxproj.user
│   ├── main.cpp
│   └── tests
│       ├── CustomerManagerTest.cpp
│       ├── CustomerTest.cpp
│       ├── MenuManagerTest.cpp
│       ├── MenuTest.cpp
│       ├── OrderManagerTest.cpp
│       ├── OrderTest.cpp
│       ├── ReviewManagerTest.cpp
│       ├── ReviewTest.cpp
│       └── testMain.cpp
└── foodOrderProgram.sln
```
