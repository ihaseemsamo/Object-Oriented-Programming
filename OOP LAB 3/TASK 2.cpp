#include<iostream>

using namespace std;

class FitnessTracker {
    string userName;
    int dailyStepsGoal;
    int stepsTaken;
    float caloriesBurned;
    float caloriesBurnedGoal;
    float perStepCaloriesBurned;

public:
    FitnessTracker(string username) {
        userName = username;
    }

    void setSteps(int StepsTaken, int DailyStepsGoal,float PerStepCaloriesBurned) {
        stepsTaken = StepsTaken;
       dailyStepsGoal = DailyStepsGoal;
       perStepCaloriesBurned = PerStepCaloriesBurned;
    }

    void calculateCalories() {
        
        caloriesBurned = perStepCaloriesBurned * stepsTaken;
        caloriesBurnedGoal = dailyStepsGoal * perStepCaloriesBurned;
        cout << "Expected Calories to be burned: " << caloriesBurnedGoal << endl;
        cout << "Actual Calories Burned: " << caloriesBurned << endl;
    }

    void notify() {
  

        if (dailyStepsGoal > stepsTaken) {
            int remain = dailyStepsGoal - stepsTaken;
            caloriesBurned = remain * perStepCaloriesBurned;
            cout << caloriesBurned << " Calories required to complete your goal." << endl;
        } else {
            cout << "Goal Achieved." << endl;
        }
    }

    void display() {
        cout << "Name: " << userName << endl;
        cout << "Daily Steps Goal: " << dailyStepsGoal << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Expected Calories Burned: " << caloriesBurnedGoal << endl;
        cout << "Actual Calories Burned: " << caloriesBurned << endl;
    }
};

int main() {
    FitnessTracker tracker("Haseem");
    
    tracker.setSteps(7000, 10000,0.75);
    
    tracker.calculateCalories();
    
    tracker.notify();
    
    tracker.display();

    return 0;
}
