# cprog20_project

### 파일설명
project.c 코드는 구조체배열을 이용해 프로젝트 기능을 구현한 스케치 코드이다. history를 보면 프로젝트 작업 과정이 나와있다.  
pro.c 코드는 project.c 코드를 다시 연결리스트와 동적할당으로 구현한 것이다. history를 보면 프로젝트 작업 과정이 나와있다.   
Music_Playlist.txt는 프로그램 실행결과 확인을 쉽게하기 위한 텍스트파일로, "나의 플레이리스트"의 저장기능으로 만들어진 파일이다.  
final폴더는 총 프로젝트의 결과물 파일로 최종 코드와 Music_Playlist.txt이 들어있다.  

### 실행방법
1. git clone을 한다.  
2. final폴더에 들어가 fanal.c 파일을 컴파일 한 뒤 실행시킨다. 

### 기능소개
1. 노래추가하기 - 노래정보를 입력하여 노래를 추가한다. (노래제목, 가수, 장르, 좋아요표시, 노래 년도)  
2. 노래삭제하기 - 노래제목을 입력하여 특정 노래 정보를 삭제한다. 
3. 플레이리스트 보기  
- 전체 리스트 보기 : 전체 노래 정보를 출력한다.   
- 필터 리스트 보기 : 필터를 선택하여 그 필터에 맞는 노래 정보를 출력한다. (가수, 장르, 좋아요)  
4. 노래 찾기 - 찾을 노래제목을 입력하여 그 노래 정보를 출력한다.
5. 노래의 연도 - 사용자의 나이를 입력하면 노래가 나온 연도에 맞게 그 당시 나이를 계산한다. 그 뒤 노래와 노래의 연도, 당시 사용자의 나이를 출력한다.  
6. 노래 재생하기 - 재생할 노래제목을 입력하여 특정 노래 재생 수를 증가시킨다. 또 재생했다고 출력한다.  
7. 나의 노래 차트보기 - 사용자가 많이 재생시킨 노래의 정보를 순서대로 출력시킨다. 
8. 저장하기 - 입력한 노래 정보들을 My_Playlist.txt파일에 저장한다.
9. 불러오기 - My_Playlist.txt파일에 저장된 노래 정보들을 불러온다.


