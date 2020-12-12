#include "Header.h"

int main() {
	Bug SpiderManDontWork("the spiderman stands still, not moving", 1, 12.20, "Resolved", "Vasiliy Petrovich");
	Bug textureDoesNotLoad("when a character appears no textures are loaded, only a white canvas", 2, 6.21, "In progress", "Vyacheslav Homenko");
	Bug theCharacterFlies("when you press M and B, the character can fly", 3, 12.3, "Unresolved", "Andriy Sergeevich");
	Bug cloudsStandStill("clouds and sun stand still compared to the player", 1, 3.04, "Resolved", "Petro Filatov");
	Bug failureUnderTheGround("when running fast, the character falls to the ground", 5, 5.06, "Doing", "Igor Ivanovich");
	BackLog Company;
	Company.insert(&SpiderManDontWork);
	Company.insert(&textureDoesNotLoad);
	Company.insert(&theCharacterFlies);
	Company.insert(&cloudsStandStill);
	Company.insert(&failureUnderTheGround);
	Company.show();
	Company.showByStatus();
	Company.shortBySeverity();
	Company.show();
	return 0;
}
