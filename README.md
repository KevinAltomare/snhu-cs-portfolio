# snhu-cs-portfolio
Portfolio repository for SNHU Computer Science program

CS210_Project3 is a C++ program developed for the Corner Grocer, designed to analyze daily text‑based purchase records and determine how frequently each item is bought. The store wants to reorganize their produce section, so the program helps them understand customer buying patterns by counting item frequencies, displaying them in multiple formats, and generating a backup data file. This project demonstrates my ability to use classes, file handling, maps, loops, and clean program structure to solve a real business problem.

1. Summary of the Project
This project involved building an item‑tracking program that reads a text file of purchased items, counts how often each item appears, and presents that information through a simple menu system. The user can search for a specific item, print a full list of item frequencies, view a histogram, and the program also creates a backup file called frequency.dat automatically. The goal was to help the Corner Grocer analyze purchasing trends so they can reorganize their produce section more effectively.

2. What I Did Well
I think I did a good job designing the class structure and using an std::map to store item frequencies. The map made it straightforward to count items and look them up quickly. I also kept the code readable by using clear naming, comments, and a logical layout. The histogram output came out clean and easy to read, which makes the program nicer to use.

3. Where I Could Enhance My Code
If I were to improve the project, I would add stronger input validation, especially for menu choices and item searches. I could also make searches case‑insensitive or support multi‑word items. Another improvement would be breaking more of the logic into helper functions to make the program even more modular. These changes would make the program more reliable, easier to maintain, and more user‑friendly.

4. Most Challenging Parts and How I Overcame Them
The hardest part was getting the file‑processing logic right and making sure the map counted items accurately without missing anything. I worked through this by testing with smaller files, printing out intermediate results, and stepping through the code with a debugger. I also went back to the zyBooks sections on file input/output and maps to make sure I was using the correct syntax. Tools like GitHub and Copilot have become part of my regular workflow for debugging and staying organized.

5. Transferable Skills
This project helped reinforce several skills that will be useful in future classes and real‑world development, including:
• Working with classes and separating public and private data
• Reading from and writing to files
• Using maps for efficient data storage
• Designing simple, user‑friendly menu systems
• Writing modular, maintainable C++ code
• Using GitHub for version control and portfolio building

6. Making the Program Maintainable, Readable, and Adaptable
I focused on writing code that someone else could understand without much effort. I used descriptive variable names, consistent formatting, and comments to explain the important parts of the logic. I also separated the program into logical components, including a class dedicated to loading data and generating the backup file. This structure makes it easier to update the program later, whether that means adding new menu options or supporting different file formats.
