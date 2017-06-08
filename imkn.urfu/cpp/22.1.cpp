#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Selection {
  public:
    unsigned int start;
    unsigned int end;
    string word;
    Selection(unsigned int start, unsigned int end, string word):
      start(start),
      end(end),
      word(word)
    {
    }
};

class Selections {
  public:
    static constexpr const char* punctuations = ",.!?:; ";
    vector<Selection> selectedWords;
    Selections(string phrase) {
      stringstream word;
      unsigned int start = 0;
      for (int i = 0; i < phrase.size(); i++) {
        // cout << phrase[i] << " " << word.str() << "\n";

        bool isPunctuation = false;
        for (char punctuation : string(punctuations)) {
          if (phrase[i] == punctuation) {
            if (word.tellp() != 0) {
              selectedWords.push_back(Selection(start, i - 1, word.str()));
              word.str("");
            }
            isPunctuation = true;
            start = i + 1;
            break;
          }
        }
        if (!isPunctuation) {
          word << phrase[i];
        }
      }
    }

    Selections(vector<Selection> selections):
      selectedWords(selections)
    {
    }

    Selections findWords() {
      vector<Selection> result;
      for (Selection selection : selectedWords) {
        if (selection.word[0] != selection.word[selection.word.length() - 1]){
          result.push_back(selection);
        }
      }
      return Selections(result);
    }
};

int main() {
  string input;
  stringstream phrase;
  cout << "enter phrase, end it with empty line\n";
  do {
    getline(cin, input);
    phrase << input << " ";
  } while (input.length() != 0);

  Selections selections = Selections(phrase.str());
  Selections words = selections.findWords();

  for (Selection selection : words.selectedWords) {
    cout << selection.word << " (" << selection.start << ":" << selection.end << ") \n";
  }
}
