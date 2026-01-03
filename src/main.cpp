#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <chrono>

using namespace geode::prelude;

int deathCount = 0;
int lastTollHour = -1;
bool tollPaidThisHour = false;

class $modify(MyPlayLayer, PlayLayer) {
    void resetLevel() {
        PlayLayer::resetLevel();

        auto now = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(now);
        std::tm* local_tm = std::localtime(&tt);
        int currentHour = local_tm->tm_hour;

        if (currentHour != lastTollHour) {
            lastTollHour = currentHour;
            tollPaidThisHour = false;
            deathCount = 0; 
        }

        if (!tollPaidThisHour) {
            deathCount++;
            if (deathCount >= 5) {
                deathCount = 0;
                geode::createQuickPopup(
                    "Adoraboo Toll!", 
                    "5 attempts reached. Paid your 6 ads for this hour?", 
                    "Not Yet", "Yes, Paid!", 
                    [this](auto, bool btn2) {
                        if (btn2) {
                            tollPaidThisHour = true;
                            Notification::create("Toll Registered! Enjoy your window.", NotificationIcon::Success)->show();
                        }
                    }
                );
            }
        }
    }
};
