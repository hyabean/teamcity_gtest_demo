#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName1, TestName1) {
	EXPECT_EQ(2, 2);
	EXPECT_TRUE(3 == 3);
}
TEST(TestCaseName1, TestName2) {
	EXPECT_EQ(2, 3);
	EXPECT_TRUE(3 == 3);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
	// Add unique flowId parameter if you want to run test processes in parallel
	// See http://confluence.jetbrains.net/display/TCD6/Build+Script+Interaction+with+TeamCity#BuildScriptInteractionwithTeamCity-MessageFlowId
	listeners.Append(new GTest::TeamCityAdapter());

	return RUN_ALL_TESTS();
}