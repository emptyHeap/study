package ru.gritsus.imkn.oop.java;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Message {
	private String string;
	
	public Message(String str) {
		this.string = str;
	}
	
	public int countWords() {
		String[] words = string.split(" ");
		return words.length;
	}
	
	public String reverse() {
		StringBuilder sb = new StringBuilder(string);
		sb.reverse();
		return sb.toString();
	}
	
	public int count(char c) {
		char[] chars = string.toCharArray();
		int count = 0;
		
		for (int i = 0; i < chars.length; i++) {
			if (chars[i] == c) {count++;}
		}
		
		return count;
	}
	
	public String series() {
		Pattern pattern = Pattern.compile("(?i:серия)\\W*(?<series>\\w+)", Pattern.UNICODE_CHARACTER_CLASS);
		Matcher matcher = pattern.matcher(string);
		String result = "no series founded";
		
		while(matcher.find()) {
			if (!result.contentEquals("no series founded")) {
				return "multiple series founded";
			}
			
			result = matcher.group("series");
		}
		
		return result;
	}
	
	public String number() {
		Pattern pattern = Pattern.compile("№\\W*(?<number>\\d+)", Pattern.UNICODE_CHARACTER_CLASS);
		Matcher matcher = pattern.matcher(string);
		String result = "";
		
		while(matcher.find()) {
			if (!result.contentEquals("")) {
				return "multiple numbers founded";
			}
			
			result = matcher.group("number");
		}
		
		return result;
	}
}
