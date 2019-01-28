package ru.gritsus.imkn.oop.java;

import ru.gritsus.imkn.oop.java.MessageTestHelper;

public class task03 {

	public static void main(String[] args) {
		MessageTestHelper[] tests = {
				new MessageTestHelper("Серия 1 № 310", "1", "310", "013 № 1 яиреС", 4, 
						new char[] {'1', '№'}, new int[] {1, 1}),
				new MessageTestHelper("Серия 1 Серия2", "multiple series founded", "", "2яиреС 1 яиреС", 3,
						new char[] {'я'}, new int[] {1}),
				new MessageTestHelper("№99десять сеРИя первая ", "первая", "99", " яавреп яИРес ьтясед99№", 3,
						new char[] {'Я', 'я'}, new int[] {0, 3})
//				{"1", "310", "Серия 1 № 310"},
//				{"1", "310", "Серия1 №310"},
//				{"1", "310", "Серия Itanium 2 № 310"},
//				{"1", "310", "Серия Itanium №2"},
//				{"1", "310", "Серия Itanium 2 серия 9000 № 310"},
//				{"1", "310", "СеРИя 1 № 310"},
//				{"1", "310", "Серия 1 № 310 серия"}
		};
		
		for (int i = 0; i < tests.length; i++) {
			tests[i].start();
		}
		
	}
	
}
