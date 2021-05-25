#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class HealthFood {
private:
    auto findMeal(std::string diet, int dietIndex, std::vector<int>& protein, std::vector<int>& carbs, std::vector<int>& fat, std::vector<int>& calories, std::vector<int>& positions) -> int {
        std::vector<int> filteredProtein;
        std::vector<int> filteredCarb;
        std::vector<int> filteredFat;
        std::vector<int> filteredCal;
        std::vector<int> filteredPos;
        switch(diet[dietIndex]) {
            case 'C': {
                auto maxCarb = std::max_element(carbs.begin(), carbs.end());
                for (size_t i = 0; i < protein.size(); i++) {
                    if(carbs[i] == *maxCarb) {
                        filteredProtein.push_back(protein[i]);
                        filteredCarb.push_back(carbs[i]);
                        filteredFat.push_back(fat[i]);
                        filteredPos.push_back(positions[i]);
                        filteredCal.push_back(calories[i]);
                    }
                }
                break;
            }
            case 'c': {
                auto minCarb = std::min_element(carbs.begin(), carbs.end());
                for (size_t i = 0; i < protein.size(); i++) {
                    if(carbs[i] == *minCarb) {
                        filteredProtein.push_back(protein[i]);
                        filteredCarb.push_back(carbs[i]);
                        filteredFat.push_back(fat[i]);
                        filteredPos.push_back(positions[i]);
                        filteredCal.push_back(calories[i]);
                    }
                }
                break;
            }
            case 'P': {
                auto maxPro = std::max_element(protein.begin(), protein.end());
                for (size_t i = 0; i < protein.size(); i++) {
                    if(protein[i] == *maxPro) {
                        filteredProtein.push_back(protein[i]);
                        filteredCarb.push_back(carbs[i]);
                        filteredFat.push_back(fat[i]);
                        filteredPos.push_back(positions[i]);
                        filteredCal.push_back(calories[i]);
                    }
                }
                break;
            }
            case 'p': {
                auto minPro = std::min_element(protein.begin(), protein.end());
                for (size_t i = 0; i < protein.size(); i++) {
                    if(protein[i] == *minPro) {
                        filteredProtein.push_back(protein[i]);
                        filteredCarb.push_back(carbs[i]);
                        filteredFat.push_back(fat[i]);
                        filteredPos.push_back(positions[i]);
                        filteredCal.push_back(calories[i]);
                    }
                }
                break;
            }
            case 'F': {
                auto maxFat = std::max_element(fat.begin(), fat.end());
                for (size_t i = 0; i < protein.size(); i++) {
                    if(fat[i] == *maxFat) {
                        filteredProtein.push_back(protein[i]);
                        filteredCarb.push_back(carbs[i]);
                        filteredFat.push_back(fat[i]);
                        filteredPos.push_back(positions[i]);
                        filteredCal.push_back(calories[i]);
                    }
                }
                break;
            }
            case 'f': {
                auto minFat = std::min_element(fat.begin(), fat.end());
                for (size_t i = 0; i < protein.size(); i++) {
                    if(fat[i] == *minFat) {
                        filteredProtein.push_back(protein[i]);
                        filteredCarb.push_back(carbs[i]);
                        filteredFat.push_back(fat[i]);
                        filteredPos.push_back(positions[i]);
                        filteredCal.push_back(calories[i]);
                    }
                }
                break;
            }
            case 'T': {
                auto maxCal = std::max_element(calories.begin(), calories.end());
                for (size_t i = 0; i < protein.size(); i++) {
                    if(calories[i] == *maxCal) {
                        filteredProtein.push_back(protein[i]);
                        filteredCarb.push_back(carbs[i]);
                        filteredFat.push_back(fat[i]);
                        filteredPos.push_back(positions[i]);
                        filteredCal.push_back(calories[i]);
                    }
                }
                break; 
            } 
            case 't': {
                auto minCal = std::min_element(calories.begin(), calories.end());
                for (size_t i = 0; i < protein.size(); i++) {
                    if(calories[i] == *minCal) {
                        filteredProtein.push_back(protein[i]);
                        filteredCarb.push_back(carbs[i]);
                        filteredFat.push_back(fat[i]);
                        filteredPos.push_back(positions[i]);
                        filteredCal.push_back(calories[i]);
                    }
                }
                break; 
            } 
        }

        if(filteredPos.size() == 1) {
            return filteredPos[0];
        }
        else if(dietIndex == diet.length() - 1) {
            return filteredPos[0];
        }
        else {
            return findMeal(diet, dietIndex + 1, filteredProtein, filteredCarb, filteredFat, filteredCal, filteredPos);
        }
    }
public:
    std::vector<int> selectMeals(std::vector<int>& protein, std::vector<int>& carbs, std::vector<int>& fat, std::vector<std::string>& dietPlans) {
        std::vector<int> calories(protein.size(), 0);
        for (size_t i = 0; i < protein.size(); i++) {
            calories[i] = (protein[i] + carbs[i]) * 5 + fat[i] * 9;
        }
        std::vector<int> positions(protein.size(), 0);
        for (size_t i = 0; i < protein.size(); i++) {
            positions[i] = i;
        }
        
        std::vector<int> indices;
        for(const auto& diet: dietPlans) {
            int index = 0;
            if(diet.length() != 0) {
                index = findMeal(diet, 0, protein, carbs, fat, calories, positions);
            }
            indices.push_back(index);
        }
        return indices;
    }
};

auto main() -> int {
    HealthFood hf;
    std::vector<int> p{18, 86, 76,  0, 34, 30, 95, 12, 21};
    std::vector<int> c{26, 56,  3, 45, 88,  0, 10, 27, 53};
    std::vector<int> f{93, 96, 13, 95, 98, 18, 59, 49, 86};
    std::vector<std::string> dp{"f", "Pt", "PT", "fT", "Cp", "C", "t", "", "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"};
    std::vector<int> res = hf.selectMeals(p, c, f, dp);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
}