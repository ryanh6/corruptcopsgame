# Corrupt Cops
The game Corrupt Cops comes from the Korean Game Show on Netflix called the Devil's Plan. I really like Korean Brain Game Survival Shows and so I figured I'd try coding one of the games. The Rules of Corrupt Cops are quite complex and are explained below...

- Originally played as 14 players, 2 players are selected as theives, the other 12 players are cops, separated into 3 teams of 4: Red, Blue and Green team. Among the 12 cops, 2 are selected to be corrupt cops, both always on different teams. Roles and team information are public knowledge however, the identities of the corrupt cops are unknown.

- Once the roles are selected, players choose a starting point on the game board, starting with Player 1 of each colour team, all the way until the last players of each team. The team order to choose starting points is always Blue -> Red -> Green. Chosen player locations of cops is public knowledge to everyone. Once all cops have chosen a location on the board, theives will choose their starting points on the board

- The goal of the regular cops is to catch the theives on the game board. However, cops are not aware / cannot see the location of the theives on the game board.
- The goal of the theives is to navigate the game board collect loot while evading getting arrested by cops. 
- The goal of the corrupt cops is to stop the regular cops from catching the theives while concealing their own identity as well. Each round, the corrupt cops are secretly notified of the theives locations on the game board. Note that the theives are aware of the identities of the corrupt cops. 

- A round of the game proceeds as follows...
- The 2 thieves will move their piece on the board, moving up to 2 spaces, in an attempt to collect loot scattered across the map. Only theives are aware of the location of the loot on the map. Whenever a thief moves, they leave behind a permanent trace on the space they left, indicating that they were at this space before
- Once the 2 thieves have moved, the corrupt cops are secretly informed of the thieves' locations.
- 

- Each round, team order of player will be shuffled

## Compiling / Running

- To compile, use the command: "g++ corruptcops.cpp -o corruptcopsgame".
- To run the file, use "./corruptcopsgame"

## Tools
## Optimizations