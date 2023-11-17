#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <cstdlib>
#include <string>

#ifdef _WIN32
#include <windows.h>
#elif defined(__APPLE__)
#include <unistd.h>
#elif defined(__linux__)
#include <unistd.h>
#endif

using namespace geode::prelude;

class $modify(MenuLayer) {
public:
    void onMoreGames(CCObject*) {
        geode::createQuickPopup(
            "Confirmation",
            "View an archive of the more games page?",
            "Yes", "No",
            [](auto, bool btn1){
                if (btn1) {
                    const std::string& url = "https://sevenworks.eu.org/moregames.html";
#ifdef _WIN32
        ShellExecuteA(NULL, "start", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
#elif defined(__APPLE__)
        std::string command = "open " + url;
        system(command.c_str());
#elif defined(__linux__)
        std::string command = "xdg-open " + url;
        system(command.c_str());
#endif
                }
            }
        );
    };
};
