#include <iostream>

int main(){
	int count = 0, dayOfTheWeek = 1;
	for(int i=1901; i<2001; i++){
		for(int k=1; k<13; k++){
			int daysInMonth;
			
			switch(k){
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					daysInMonth = 31;
					break;
				case 4: case 6: case 9: case 11:
					daysInMonth = 30;
					break;
				case 2:
					if(i%4==0) daysInMonth = 29;
					else daysInMonth = 28;
					break;
			}
			
			dayOfTheWeek = (daysInMonth+dayOfTheWeek)%7;
			if(dayOfTheWeek==6) count++;
		}
	}
	std::cout << count << '\n';
    return 0;
}
