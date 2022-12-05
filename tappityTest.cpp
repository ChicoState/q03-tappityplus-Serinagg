/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
#include <string>

using namespace std;

class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

/*testing constructor: setting reference phrase */
TEST(tappityTest, reference_set_empty)
{
	ASSERT_ANY_THROW(
	{
		string refer = "";
		tappity tiptap(refer);
	});
}

TEST(tappityTest, reference_set_letter)
{
	ASSERT_NO_THROW(
	{
		string refer = "a";
		tappity tiptap(refer);
	});
}

TEST(tappityTest, reference_set_char)
{
	ASSERT_NO_THROW(
	{
		string refer = "%";
		tappity tiptap(refer);
	});
}


TEST(tappityTest, reference_set_lowerWord)
{
	ASSERT_NO_THROW(
	{
		string refer = "apple";
		tappity tiptap(refer);
	});
}

TEST(tappityTest, reference_set_capitalWord)
{
	ASSERT_NO_THROW(
	{
		string refer = "Apple";
		tappity tiptap(refer);
	});
}


TEST(tappityTest, reference_set_lowerSentence)
{
	ASSERT_NO_THROW(
	{
		string refer = "apples grow on trees.";
		tappity tiptap(refer);
	});
}

TEST(tappityTest, reference_set_capitalSentence)
{
	ASSERT_NO_THROW(
	{
		string refer = "Apples grow on trees.";
		tappity tiptap(refer);
	});
}

/* testing entry function: getting user's input */
TEST(tappityTest, input_set_empty)
{
	ASSERT_NO_THROW(
	{
		string refer = "Apples grow on trees.";	
		string in = "";
		tappity tiptap(refer);
		tiptap.entry(in);
	});
}

TEST(tappityTest, input_set_char)
{
	ASSERT_NO_THROW(
	{
		string refer = "Apples grow on trees.";	
		string in = "&";
		tappity tiptap(refer);
		tiptap.entry(in);
	});
}

TEST(tappityTest, input_set_capitalWord)
{
	ASSERT_NO_THROW(
	{
		string refer = "Apples grow on trees.";	
		string in = "Apple";
		tappity tiptap(refer);
		tiptap.entry(in);
	});
}

TEST(tappityTest, input_set_lowerWord)
{
	ASSERT_NO_THROW(
	{
		string refer = "Apples grow on trees.";	
		string in = "apple";
		tappity tiptap(refer);
		tiptap.entry(in);
	});
}

TEST(tappityTest, input_set_capitalSentence)
{
	ASSERT_NO_THROW(
	{
		string refer = "Apples grow on trees.";	
		string in = "Apples grow on trees.";
		tappity tiptap(refer);
		tiptap.entry(in);
	});
}

TEST(tappityTest, input_set_lowerSentence)
{
	ASSERT_NO_THROW(
	{
		string refer = "Apples grow on trees.";	
		string in = "apples grow on trees.";
		tappity tiptap(refer);
		tiptap.entry(in);
	});
}

TEST(tappityTest, input_set_doubleEntry)
{
	ASSERT_ANY_THROW(
	{
		string refer = "Apples grow on trees.";	
		string in = "Apples grow on trees.";
		tappity tiptap(refer);
		tiptap.entry(in);
		in = "apples";
		tiptap.entry(in);
	});
}

/*testing length_difference function: returns difference between reference and input length */

TEST(tappityTest, lengDiff_emptyInput)
{
	string refer = "Apples grow on trees.";	
	string in = "";
	tappity tiptap(refer);
	tiptap.entry(in);
	int act_diff = tiptap.length_difference();
	ASSERT_EQ(refer.length(), act_diff);
}

TEST(tappityTest, lengDiff_equalLeng)
{
	string refer = "Apples grow on trees.";	
	string in = "serina eats on plates";
	tappity tiptap(refer);
	tiptap.entry(in);
	int act_diff = tiptap.length_difference();
	ASSERT_EQ(0, act_diff);
}

TEST(tappityTest, lengDiff_longerInput)
{
	string refer = "Apples grow on trees.";	
	string in = "Christmas time is during the winter season.";
	tappity tiptap(refer);
	tiptap.entry(in);
	int act_diff = tiptap.length_difference();
	int exp_diff = in.length() - refer.length();
	ASSERT_EQ(exp_diff, act_diff);
}

TEST(tappityTest, lengDiff_longerReference)
{
	string in = "Apples grow on trees.";	
	string refer = "Christmas time is during the winter season.";
	tappity tiptap(refer);
	tiptap.entry(in);
	int act_diff = tiptap.length_difference();
	int exp_diff = refer.length() - in.length();
	ASSERT_EQ(exp_diff, act_diff);
}

/*testing accuracy function: returns percentage */
TEST(tappityTest, accuracy_exactMatch)
{
	string refer = "Apples grow on trees.";	
	string in = "Apples grow on trees.";
	tappity tiptap(refer);
	tiptap.entry(in);
	double act_acc = tiptap.accuracy();
	ASSERT_EQ(double(100), act_acc);
}

TEST(tappityTest, accuracy_halfMatch)
{
	string refer = "Apples grow on trees";	
	string in = "Apples gro";
	tappity tiptap(refer);
	tiptap.entry(in);
	double act_acc = tiptap.accuracy();
	ASSERT_EQ(double(50), act_acc);
}

TEST(tappityTest, accuracy_emptyInput)
{
	string refer = "Apples grow on trees.";	
	string in = "";
	tappity tiptap(refer);
	tiptap.entry(in);
	double act_acc = tiptap.accuracy();
	ASSERT_EQ(double(0), act_acc);
}

TEST(tappityTest, accuracy_noMatch)
{
	string refer = "Apples grow on trees.";	
	string in = "serina.eats.to.plates";
	tappity tiptap(refer);
	tiptap.entry(in);
	double act_acc = tiptap.accuracy();
	ASSERT_EQ(double(0), act_acc);
}

TEST(tappityTest, accuracy_longerInput)
{
	string refer = "Apples grow on trees";	
	string in = "Apple is a healthy fruit.";
	tappity tiptap(refer);
	tiptap.entry(in);
	double act_acc = tiptap.accuracy();
	ASSERT_EQ(double(24), act_acc);
}

TEST(tappityTest, accuracy_longerReference)
{
	string in = "Apples grow on trees";	
	string refer = "Apple is a healthy fruit.";
	tappity tiptap(refer);
	tiptap.entry(in);
	double act_acc = tiptap.accuracy();
	ASSERT_EQ(double(24), act_acc);
}
