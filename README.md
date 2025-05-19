# Corrupt Cops
The game Corrupt Cops comes from the Korean Game Show on Netflix called the Devil's Plan. I really like Korean Brain Game Survival Shows and so I figured I'd try coding one of the games. The Rules of Corrupt Cops are quite complex and are explained below...

- Originally played as 14 players, 2 players are selected as theives, the other 12 players are cops, separated into 3 teams of 4: Red, Blue and Green team. However among the 12 cops, there exists 2 corrupt cops, both always on different teams. Note that with the exception of which cops are corrupt, all roles and team information are public knowledge.
- The goal of the regular cops is to catch the theives on the game board. However, cops are not aware / cannot see the location of the theives on the game board.
- The goal of the theives is to navigate the game board collect loot while evading getting arrested by cops. 
- The goal of the corrupt cops is to stop the regular cops from catching the theives while concealing their own identity as well. Each round, the corrupt cops are secretly notified of the theives locations on the game board. Note that the theives are aware of the identities of the corrupt cops. 

## Compiling / Running

To compile, use the command: "g++ corruptcops.cpp -o corruptcopsgame". To run the file, use "./corruptcopsgame"

## Tools
## Optimizations