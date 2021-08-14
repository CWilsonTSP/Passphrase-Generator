#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Read a file name and return a vector of the lines in it
std::vector<std::string> read_file(std::string name)
{
    std::vector<std::string> rv;

    std::ifstream fin(name);
    // std::ifstream fadj("lists/");

    if( !fin ) {
        std::cout << "Error opening input file" << std::endl;
        exit(1) ;
    }

    std::string line;

    for( int i = 0; !fin.eof(); i++) {
        getline( fin , line );
        // std::cerr << line << std::endl;
        // add word to array
        rv.push_back(line);
    }
    fin.close() ;

    return rv;

}

// Capitalize the first letting in the string val
std::string cap_first(std::string val)
{
    std::string rv = val;
    rv[0] = toupper(rv[0]);
    return rv;
}

// generate a password by randomly choosing a noun and two adjectives
std::string generate(std::vector<std::string> nouns, std::vector<std::string> adjs)
{
    // seed time for random to work
    srand(time(NULL));

    // pick three random works
    int nadj1 = rand() % adjs.size(); // adjective
    int nadj2 = rand() % adjs.size(); // adjective
    int nnoun = rand() % nouns.size(); // and a noun

    // debug print the random numbers
    // std::cerr << std::to_string(nadj1) + " " + std::to_string(nadj2) + " "+ std::to_string(nnoun) << std::endl; 
    // grab the strings of the the words from our vectors
    // and capitalize them
    std::string adj1 = cap_first(adjs[nadj1]);
    std::string adj2 = cap_first(adjs[nadj2]);
    std::string noun = cap_first(nouns[nnoun]);

    // Concatenate them together
    std::string passphrase = adj1 + adj2 + noun; 

    std::string vowels = "aeiouAEIOU";
    bool vowel = false;
    // check if the first letter is a vowel.
    // If so, prepend "An"
    for (int i = 0; i < vowels.length(); ++i){
        if (passphrase[0] == vowels[i]){
            passphrase = "An" + passphrase;
            vowel = true;
            break;
        }
    } // else, prepend "a"
    if (vowel == false){
        passphrase = "a" + passphrase;
    }

    // return our passphrase
    return passphrase;
}

int main()
{
    // load all the word lists
    // This could be optimized by having them listed here and compiled rather
    //      than dynamically loaded, but I figure that this way you could add
    //      an arbitrary amount of words to your list and still run the 
    //      generator without compiling.
    // std::cerr << "Reading in Nouns" << std::endl;
    std::vector<std::string> nouns = read_file("lists/nouns");
    // std::cerr << "Reading in Adjectives" << std::endl;
    std::vector<std::string> adjs = read_file("lists/adjs");

    // std::cerr << "Loaded in words. Generating passphrases." << std::endl;

    // generate the passphrase. 
    std::string passphrase = generate(nouns, adjs);
    // print out the final passphrase
    std::cout << passphrase << std::endl;

    return 0;
}
