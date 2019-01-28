package ru.gritsus.imkn.oop.java;

import ru.gritsus.imkn.oop.java.Message;

class MessageTestHelper {
	String expectedSeries;
	String expectedNumber;
	String expectedReverse;
	String originalString;
	int expectedWordsCount;
	char[] characters;
	int[] charactersCount;
	
	MessageTestHelper(String original, String series, String number, String reverse, int wordCount, char[] characters, int[] charactersCount) {
		this.originalString = original;
		this.expectedSeries = series;
		this.expectedNumber = number;
		this.expectedReverse = reverse;
		this.expectedWordsCount = wordCount;
		if (characters.length == charactersCount.length) {
			this.characters = characters;
			this.charactersCount = charactersCount;
		}
	}
	
	void start() {
		Message message = new Message(originalString);
		
		this.check(expectedSeries.contentEquals(message.series()), "series", expectedSeries, message.series());
		this.check(expectedNumber.contentEquals(message.number()), "number", expectedNumber, message.number());
		this.check(expectedWordsCount == message.countWords(), "words count", expectedWordsCount, message.countWords());
		this.check(expectedReverse.contentEquals(message.reverse()), "reverse", expectedReverse, message.reverse());
		
		for (int i = 1; i < characters.length; i++) {
			this.check(message.count(characters[i]) == charactersCount[i], "character count for \""+characters[i]+"\"",
					charactersCount[i], message.count(characters[i]));
		}
	}
	
	void check(boolean e, String testName, String expected, String received) {
		if (!e) {
			System.out.println("String \""+originalString+"\" failed \""+testName+"\" test");
			System.out.println("Expected: \""+expected+"\"; Received: \""+received+"\"\n");
		}
	}
	
	void check(boolean e, String testName, int expected, int received) {
		this.check(e, testName, String.valueOf(expected), String.valueOf(received));
	}
}
