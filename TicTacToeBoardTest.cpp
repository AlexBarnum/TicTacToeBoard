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
TEST(TicTacToeBoardTest, placColOver2)
{
	TicTacToeBoard obj;
	Piece outcome = obj.placePiece(2,3);
	ASSERT_EQ(outcome, Invalid);
}
TEST(TicTacToeBoardTest, placeRowAndColOver2)
{
	TicTacToeBoard obj;
	Piece outcome = obj.placePiece(3,3);
	ASSERT_EQ(outcome, Invalid);
}
TEST(TicTacToeBoardTest, placeX00)
{
	TicTacToeBoard obj;
	Piece outcome = obj.placePiece(0,0);
	ASSERT_EQ(outcome, X);
}
TEST(TicTacToeBoardTest, placeX22)
{
	TicTacToeBoard obj;
	Piece outcome = obj.placePiece(2,2);
	ASSERT_EQ(outcome, X);
}
TEST(TicTacToeBoardTest, placeO)
{
	TicTacToeBoard obj;
	obj.toggleTurn();
	Piece outcome = obj.placePiece(0,0);
	ASSERT_EQ(outcome, O);
}
TEST(TicTacToeBoardTest, placeOoverX)
{
	TicTacToeBoard obj;
	Piece outcome = obj.placePiece(0,0);
	outcome = obj.placePiece(0,0);
	ASSERT_EQ(outcome, X);
}
TEST(TicTacToeBoardTest, placeXandO)
{
	TicTacToeBoard obj;
	Piece outcome1 = obj.placePiece(0,0);
	Piece outcome2 = obj.placePiece(0,1);
	ASSERT_EQ(outcome1, X);
	ASSERT_EQ(outcome2, O);
}
TEST(TicTacToeBoardTest, WinfirstcolX)
{
	TicTacToeBoard obj;
	Piece outcome1 = obj.placePiece(0,0);
	obj.toggleTurn();
	Piece outcome2 = obj.placePiece(1,0);
	obj.toggleTurn();
	Piece outcome3 = obj.placePiece(2,0);
	Piece outcome4 = obj.getWinner();
	ASSERT_EQ(outcome1, X);
	ASSERT_EQ(outcome2, X);
	ASSERT_EQ(outcome3, X);
	ASSERT_EQ(outcome4, X);
}
TEST(TicTacToeBoardTest, WinfirstrowX)
{
	TicTacToeBoard obj;
	Piece outcome1 = obj.placePiece(0,0);
	obj.toggleTurn();
	Piece outcome2 = obj.placePiece(0,1);
	obj.toggleTurn();
	Piece outcome3 = obj.placePiece(0,2);
	Piece outcome4 = obj.getWinner();
	ASSERT_EQ(outcome1, X);
	ASSERT_EQ(outcome2, X);
	ASSERT_EQ(outcome3, X);
	ASSERT_EQ(outcome4, X);
}
TEST(TicTacToeBoardTest, WinCross)
{
	TicTacToeBoard obj;
	Piece outcome1 = obj.placePiece(0,0);
	obj.toggleTurn();
	Piece outcome2 = obj.placePiece(1,1);
	obj.toggleTurn();
	Piece outcome3 = obj.placePiece(2,2);
	Piece outcome4 = obj.getWinner();
	ASSERT_EQ(outcome1, X);
	ASSERT_EQ(outcome2, X);
	ASSERT_EQ(outcome3, X);
	ASSERT_EQ(outcome4, X);
}
TEST(TicTacToeBoardTest, WinCrossOpp)
{
	TicTacToeBoard obj;
	Piece outcome1 = obj.placePiece(0,2);
	obj.toggleTurn();
	Piece outcome2 = obj.placePiece(1,1);
	obj.toggleTurn();
	Piece outcome3 = obj.placePiece(2,0);
	Piece outcome4 = obj.getWinner();
	ASSERT_EQ(outcome1, X);
	ASSERT_EQ(outcome2, X);
	ASSERT_EQ(outcome3, X);
	ASSERT_EQ(outcome4, X);
}
TEST(TicTacToeBoardTest, WinInvalid)
{
	TicTacToeBoard obj;
	Piece outcome = obj.getWinner();
	ASSERT_EQ(outcome, Invalid);
}
