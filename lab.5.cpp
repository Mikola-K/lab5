#include "Header.h"

int main() {
	Bag First("okd", 0, 12.20, "Resolved", "Petya");
	Bag Second("dasd", 342, 123123.123, "dasda", "dasdas");
	Bag Third("sdjajnkad", 33, 12.3, " dasdas", "asdok");
	Bag Four("sadads", 1, 123, "dasd", "das");
	Bag Five("sadsas", 666, 123, "dasd", "das");
	BackLog One;
	One.insert(&First);
	One.insert(&Second);
	One.insert(&Third);
	One.insert(&Four);
	One.insert(&Five);
	One.show();
	One.showByStatus();
	One.shortBySeverity();
	One.show();
	return 0;
}
