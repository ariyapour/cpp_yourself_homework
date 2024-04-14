#include <iostream>
#include <random>


int main(){
    //Print the welcome statement.
    std::cout<< "Welcome to the GUESSING GAME!"<<std::endl<<"I will generate a number and you will guess it!"<<std::endl;

    //Define the lower bound of guessing range
    int lower_bound{};

    //Ask the user for the smallest number
    std::cout<<"Please provide the smallest number:"<<std::endl;
    std::cin>> lower_bound;

    //Define the uper bound of guessing range
    int upper_bound{};

    //Ask the user for the smallest number
    std::cout<<"Please provide the largest number:"<<std::endl;
    std::cin>> upper_bound;

    //Define a variable to store the generated random number
    int random_number_to_guess{};

    //Generate the random number
    std::random_device random_device;
    std::mt19937 random_engine{random_device()};
    std::uniform_int_distribution distribution{lower_bound, upper_bound};
    random_number_to_guess = distribution(random_engine);

    //Inform the user that we have generated a random number in the specified range.
    std::cout<<"I've generated a number. Try to guess it!"<<std::endl;

    //Define a variable to store current guessed number
    int user_guess{-1};

    //Define a variable to store the number of guesses
    int number_of_guesses{0};

    while(true){
        //Ask the user to provide their next guess:
        std::cout<<"Please provide the next guess: ";
        std::cin>> user_guess;

        //Check the user guess
        if(user_guess == random_number_to_guess){
            //Increment the guess counter by 1
            number_of_guesses++;
            std::cout<<"You've done it! You guessed the number "<< random_number_to_guess<<" in "<< number_of_guesses<< " guesses!"<<std::endl;
            break;
        }else if(user_guess < random_number_to_guess){
            //Increment the guess counter by 1
            number_of_guesses++;
            std::cout<<"Your number is too small. Try again!"<<std::endl;
        }else{
            //Increment the guess counter by 1
            number_of_guesses++;
            std::cout<<"Your number is too big. Try again!"<<std::endl;
        }
    }
}