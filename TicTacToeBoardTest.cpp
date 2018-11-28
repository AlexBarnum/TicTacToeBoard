/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
TEST(TicTacToeBoardTest, toggleOne)
{
	TicTacToeBoard obj;
	Piece outcome = obj.toggleTurn();
	ASSERT_EQ(outcome, O);
}
TEST(TicTacToeBoardTest, toggleTwo)
{
	TicTacToeBoard obj;
	Piece outcome = obj.toggleTurn();
	outcome = obj.toggleTurn();
	ASSERT_EQ(outcome, X);
}
TEST(TicTacToeBoardTest, toggleThree)
{
	TicTacToeBoard obj;
	Piece outcome = obj.toggleTurn();
	outcome = obj.toggleTurn();
	outcome = obj.toggleTurn();
	ASSERT_EQ(outcome, O);
}


TEST(TicTacToeBoardTest, placeRowOver2)
{
	TicTacToeBoard obj;
	Piece outcome = obj.placePiece(3,2);
	ASSERT_EQ(outcome, Invalid);
}
