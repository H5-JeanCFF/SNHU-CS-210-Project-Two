# SNHU CS 210 Project Two
# Airgead Banking App Overview
The Airgead Banking App is a C++ application designed to provide users with a clear understanding of how their investments can grow over time, with a specific focus on the power of compound interest. The application allows users to input their initial investment amount, monthly deposit, annual interest rate, and the number of years they intend to invest for. The app generates detailed reports displaying year-end balances and earned interest, both with and without additional monthly deposits. This feature enables users to make informed investment decisions and comprehend the benefits of compound interest.
# Requirements
Screen Display: A screen interface where users can input the following details:
- Initial Investment Amount
- Monthly Deposit
- Annual Interest (Compounded)
- Number of Years
- User prompt for continuation

![image](https://github.com/H5-JeanCFF/SNHU-CS-210-Project-Two/assets/138174212/c91d493c-4404-4e71-adb2-c23ac62851d8)

Static Reports: Two separate static reports:
- Report 1: Year-end balances and earned interest without additional monthly deposits
- Report 2: Year-end balances and earned interest with additional monthly deposits

![image](https://github.com/H5-JeanCFF/SNHU-CS-210-Project-Two/assets/138174212/4be4b0e6-755d-4c53-b611-15d7c380e1a8)


Calculation Parameters:
- Month: Calculation of the total number of months based on the user's input for the number of years.
- Opening Amount: Calculation of the initial investment amount and opening balance each month, inclusive of interest.
- Deposited Amount: Fixed dollar amount deposited monthly.
- Total: Sum of the opening and deposited amounts.
- Interest: Calculation of the interest earned based on the annual interest rate provided by the user.

![image](https://github.com/H5-JeanCFF/SNHU-CS-210-Project-Two/assets/138174212/c39e06dd-232a-466c-ae32-48f30df89e52)

# What did you do particularly well? 
I did well designed a simple menu interface that gives the option to re-enter values and re-print any report. Also, I added a months report section which displays the monthly calculated values in an organized and easily understandable format, showing the users how the money monthly grow. 

![image](https://github.com/H5-JeanCFF/SNHU-CS-210-Project-Two/assets/138174212/5b770ad7-a307-4639-9ebf-e48845a3ec7b)


# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on? 
One improvement could be the integration of file handling functionalities. This would allow users to save generated reports in text files, enabling them to access and review the data in a specific directory.
Another improvement could involve the use of try-catch blocks to handle potential exceptions effectively, ensuring that the application doesn't crash unexpectedly and providing a smoother user experience.
# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network? 
One of the most challenging aspects was implementing the calculation of compound interest and the total amount. I overcame this challenge by referring to reliable online resources and reviewing the financial calculation formulas provided to ensure the accuracy of the implemented logic. Another challenge was ensuring comprehensive and efficient code commenting. To overcome this, I utilized resources on effective commenting practices and considered various perspectives to ensure the comments are helpful and informative for other developers who might work on the code. Additionally, I incorporated inline comments to clarify complex calculations and processes for better understanding. 
# What skills from this project will be particularly transferable to other projects or course work? 
I improved my commenting and data presentation skills. I have improved my skills to write more professional and comprehensive comments, enhancing the readability and understanding of the code for any future developers who may interact with it. Additionally, by creating more visually appealing tables like MySQL tables style, I enhanced my ability to present data in a clear, organized, and user-friendly manner, which can be applicable in various projects. 
# How did you make this program maintainable, readable, and adaptable?
I followed the guidelines provided in Airgead Banking's document, leveraging their prescribed header, class members, and parameters structure, which contributed to the maintainability and readability of the code. I ensured to write specific functionalities into separate functions, avoiding redundant code and improving code reusability and adaptability. This approach also facilitated the identification of potential bugs, leading to a more maintainable and better program structure. 
