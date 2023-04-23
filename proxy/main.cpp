#include <iostream>
#include "Types.h"

int main() {
    std::vector<Video> videos = {
            Video("test1", "1", "abcd"),
            Video("test2", "2", "dcba"),
            Video("test3", "3", "asdfsdf"),
            Video("test4", "4", "asdfasdfsdf"),
    };
    ThirdPartyYoutubeClass youtubeClass(videos);
    CachedYoutubeClass cachedYoutubeClass(&youtubeClass);
    std::cout<<"CONTENT: "<<cachedYoutubeClass.downloadVideo("2")<<"\n";
    std::cout<<"CONTENT: "<<cachedYoutubeClass.downloadVideo("3")<<"\n";
    std::cout<<"CONTENT: "<<cachedYoutubeClass.downloadVideo("2")<<"\n";
    return 0;
}
