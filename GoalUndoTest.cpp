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

TEST(GoalUndoTest, notEmptyGoalCheck)
{	
	GoalUndo g;
	g.addOperation("Draw Square");
	g.addOperation("Draw Square","Draw Horrizontal line");
	g.addOperation("Draw Square","Rotate Right 90 degree");
	g.undoGoal();
	ASSERT_EQ("Draw Square",g.getGoal());
	//ASSERT_EQ("Draw Horrizontal line",g.getOperations());	
}

TEST(GoalUndoTest, emptyOperationCheck)
{	
	GoalUndo g;
	g.undoOperation();
	ASSERT_EQ("",g.getOperations());
}

TEST(GoalUndoTest, emptyOperationEmptyGoalCheck)
{	
	GoalUndo g;
	g.addOperation("Draw Square");
	g.addOperation("Draw Horrizontal line");
	g.undoOperation();
	g.undoOperation();
	ASSERT_EQ("",g.getOperations());	
}

TEST(GoalUndoTest, notEmptyOperationCheck)
{	
	GoalUndo g;
	g.addOperation("Draw Square");
	g.undoOperation();
	ASSERT_EQ("",g.getOperations());		
}

TEST(GoalUndoTest, argNotEmptyOperationCheck)
{	
	GoalUndo g;
	g.addOperation("Draw Square");
	g.undoOperation("Draw");
	ASSERT_EQ("Draw Square",g.getOperations());		
}

TEST(GoalUndoTest, argEmptyOperationCheck)
{	
	GoalUndo g;
	g.undoOperation("Draw Triangle");
	ASSERT_EQ("",g.getOperations());
}

TEST(GoalUndoTest, argIterNotMatchCheck)
{	
	GoalUndo g;
	g.addOperation("Draw Square");
	g.addOperation("Draw Horrizontal line");
	g.undoOperation("Draw Horrizontal line");
	ASSERT_EQ("Draw Square",g.getOperations());
}

TEST(GoalUndoTest, undoOperationInMiddleCheck)
{	
	GoalUndo g;
	g.addOperation("Draw Square");
	g.addOperation("Draw Horrizontal line");
	g.addOperation("Rotate right 90 degree");
	g.addOperation("Draw Vertical line");
	g.undoOperation("Rotate right 90 degree");
	ASSERT_EQ("Draw Square Draw Horrizontal line Draw Vertical line",g.getOperations());
}