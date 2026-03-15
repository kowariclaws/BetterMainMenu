#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {

	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto winSize = CCDirector::get()->getWinSize();

	    bool hideGroundAndIcons = Mod::get()->getSettingValue<bool>("hideGroundAndIcons");
		
		log::info("mod loaded so thats a good sign i think");

		if (auto bottomMenu = getChildByID("bottom-menu")) {
			bottomMenu->setAnchorPoint({1.f, 0.f});
            bottomMenu->setPosition(winSize.width - 2.f, 0.f);
			
			if (auto ngBtn = bottomMenu->getChildByID("newgrounds-button")) {
				ngBtn->removeFromParent();
				bottomMenu->updateLayout();
			}
		}

		if (auto moreGamesMenu = getChildByID("more-games-menu")) {
			moreGamesMenu->removeFromParent();
		}
		
		if (auto socialMediaMenu = getChildByID("social-media-menu")) {
			socialMediaMenu->removeFromParent();
		}

		if (auto menuBG = getChildByID("main-menu-bg")) {
			if (hideGroundAndIcons) {
				for (auto child : menuBG->getChildrenExt()) {
					if (child->getID() != "background") {
						child->setVisible(false);
					}
				}
			}
		}

		if (auto playButtons = getChildByID("main-menu")) {		
    		playButtons->setPositionY(playButtons->getPositionY() - 11.5f);
		}

		if (auto rightMenu = getChildByID("right-side-menu")) {
				rightMenu->setAnchorPoint({1.f, 0.f});
    			rightMenu->setPosition(winSize.width - 7.f, -5.f);
		}

		if (auto gdLogo = getChildByID("main-title")) {
			gdLogo->setAnchorPoint({0.f, 1.f});
			gdLogo->setPosition({0.f, winSize.height});
		}

		if (auto closeMenu = getChildByID("close-menu")) {
			// probably compatible with restart buttons mod if i do this lol
			auto closeLayout = ColumnLayout::create();
			closeLayout->setAxisAlignment(AxisAlignment::End);
			closeLayout->setGap(4.f);
			closeLayout->setAxisReverse(true);
			closeLayout->setCrossAxisOverflow(true);

			closeMenu->setLayout(closeLayout);
			closeMenu->setAnchorPoint({1.f, 1.f});
			closeMenu->setPosition(winSize.width - 5.2f, winSize.height - 4.f);
			closeMenu->updateLayout();
		}

		if (auto profileMenu = getChildByID("profile-menu")) {
			profileMenu->setAnchorPoint({0.0f, 0.0f});
			profileMenu->setPosition(1.f, 7.f);
		
		if (auto profileButton = profileMenu->getChildByID("profile-button")) {
			if (auto username = getChildByID("player-username")) {
				username->setAnchorPoint({0.f, 0.5f});
				username->setPosition({
					profileButton->getPositionX() + profileButton->getContentSize().width * (1.f - profileButton->getAnchorPoint().x) + 4.f,
					profileButton->getPositionY() + profileButton->getContentSize().height * (0.64f - profileButton->getAnchorPoint().y)
				});
			}
		}
	}
	
	return true;
	}	
};	
