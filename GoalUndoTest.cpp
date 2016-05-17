/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
 
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoalUndoTest, getGoalCheck)
{	GoalUndo g;
	g.addOperation("Draw Square");
	g.addOperation("Draw Square","Draw Horrizontal line");
	ASSERT_EQ("Draw Square",g.getGoal());
}

TEST(GoalUndoTest, getOperationCheck)
{	GoalUndo g;
	g.addOperation("Draw Square");
	g.addOperation("Draw Square","Draw Horrizontal line");
	g.addOperation("Draw Square","Rotate Right 90 degree");
	ASSERT_EQ("Rotate Right 90 degree",g.getOperations());
}

TEST(GoalUndoTest, getTopMostGoalCheck)
{	GoalUndo g;
	g.addOperation("Draw Square");
	g.addOperation("Draw Square","Draw Horrizontal line");
	g.addOperation("Draw Square","Rotate Right 90 degree");
	g.addOperation("Draw Triangle");
	g.addOperation("Draw Triangle","Draw Horrizontal line");
	g.addOperation("Draw Triangle","Rotate Left 60 degree");
	ASSERT_EQ("Draw Triangle",g.getGoal());
}

TEST(GoalUndoTest, emptyGoalCheck)
{	
	GoalUndo g;
	g.undoGoal();
	ASSERT_EQ("",g.getGoal());	
}