# Search-Suggestion-System

#Cache.txt 
As a Sample input we have chosen the most common 1000 words used in English from this gist : https://gist.github.com/deekayen/4148741

#SearchSuggestionSystem.cpp
This File contains the main program which works the following way :

1. Load all the words previously searched (Which we have taken to be Cache.txt)
2. Add all the words using appropriate Data Structure.
3. Start Taking input from user letter by letter and calculate results for the same.
4. When The user enters '.' we assume the word is complete and we show the final results.
5. Add the Searched Word in the Data Structure as well as Cache.txt if it is not present.

