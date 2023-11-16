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
        openURL("https://sevenworks.eu.org/moregames.html");
    }

private:
    void openURL(const std::string& url) {
#ifdef _WIN32
        ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
#elif defined(__APPLE__)
        std::string command = "open " + url;
        system(command.c_str());
#elif defined(__linux__)
        std::string command = "xdg-open " + url;
        system(command.c_str());
#endif
    }
};
