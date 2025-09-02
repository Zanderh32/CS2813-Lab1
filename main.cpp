#include <iostream>
#include <string>
using namespace std;

class Text2Compress {
protected:
    int _seq[200000];    // stores current sequence
    int _length;         // length of sequence
    int _freq[640][640]; // pair frequency matrix
    int _rules[512][3];  // merge rules a b -> z
    int _ruleCount;      // number of rules learned
    int _maxSymbol;      // highest symbol ID

public:
    Text2Compress();
    void initialize(int k, int lines); // read input
    void train(int k);                 // perform merges
    void encode();                     // apply merges
    void decode();                     // expand compressed form
    void displaySequence();            // print sequence
    void displayRules();               // print learned rules
};

// ---------------- Main -----------------
int main() {
    int k, numLines;
    cin >> k >> numLines;
    cin.ignore();

    Text2Compress compressor;

    // Step 1: initialize with text
    compressor.initialize(k, numLines);

    // Step 2: train merges
    compressor.train(k);

    // Step 3: show rules
    compressor.displayRules();

    // Step 4: show compressed sequence
    compressor.displaySequence();

    // Step 5: decoding (optional)
    // compressor.decode();

    return 0;
}
