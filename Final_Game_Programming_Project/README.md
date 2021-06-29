**Description**

- Console Game, players are able to create and login with their own created characters
- Players are able to choose between modes as single or multiplayer
- Player can decide to fight bot by difficulty or player.  
- Able to level up their characters that they created by fighting in multiplayer
- Each role has their own unique set of abilities

**Project Description**
- Project uses Model-View-Controller Design Patter.
- Viewer handles the display of data used for controller
- Controller handles the flow of data given by the user and the Model
  - Controller also helps management with creating accounts and player login functionalities
  - Controller helps transition fighting and special ability fighting sequences between players
  - Transitioning fighting sequence whether player pvp, or fighting CPU.

- Model Handles the information such as the following
    * Character role transition
    * Character functionality to use their role unique abilities
    * Changing to different roles, for different fights

** Future Features In Progress**
- Able to transition and use abilities related to the given role
- Able to keep track of scoreboard of wins and losses from each match
- Available to keep track of how many characters are created in their account
- Leveling and getting experience system handling
- Using the Factory Design Pattern to implement players functionalities
- In progress is creating a filesystem to handle current directory depending on users operating system
- Debugging and refactoring for reusability

