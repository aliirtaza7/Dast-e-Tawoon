#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;

float brick_width;
int flag=0,temp=0;
double build_len,build_width;
double lbrick,hbrick,wbrick,V_brick,cost;
double calcost_partitionwall(double buildlength, double height)
{
	double wall_area=(buildlength)*height;//area of single partition wall
	double V_wall= wall_area*(wbrick);
	int number_of_bricks= int(V_wall/V_brick);
	return number_of_bricks*cost;//cost of one partition wall
}
double calcost_corridorwalls(double buildlength, double height)
{
	double wall_area=(2*buildlength)*height;//area of both the corridor walls
	double V_wall= wall_area*(wbrick);
	int number_of_bricks= int(V_wall/V_brick);
	return number_of_bricks*cost;
}
double calcost_ceiling(double build_area, double cost_of_floor)
{
	double thick;
	int c,s,a,totalparts;//for concrete ratio
	cout<<"Enter the thickness of ceiling : "<<endl;
	cin>>thick;
	cout<<"Enter the concrete mix ratio: "<<endl;
	cout<<"Cement : ";
	cin>>c;
	cout<<"Sand : ";
	cin>>s;
	cout<<"Aggregates : ";
	cin>>a;
	totalparts=c+s+a;
	double V_concrete= build_area*thick;
	float V_cement=(c/totalparts) * V_concrete;
	float V_sand=(s/totalparts) * V_concrete;
	float V_aggregates=(a/totalparts) * V_concrete;
	cout<<"Enter the weight of one bag of cement, sand, and aggregates: "<<endl;
	double weight;
	cin>>weight;
	double V_onebagcement= (weight/1440);
	double V_onebagsand=(weight/1600);
	double V_onebagaggregates=(weight/1500);
	int no_ofbagscement= (int)(V_cement/V_onebagcement);
	int no_ofbagssand= (int)(V_sand/V_onebagsand);
	int no_ofbagsaggregates= (int)(V_aggregates/V_onebagaggregates);
	cout<<"Enter the cost of one bag of cement, sand, and aggregates: "<<endl;
	double cost_cement,cost_sand,cost_agg;
	cin>>cost_cement>>cost_sand>>cost_agg;
	//stores the total cost of concrete ratios in the cost of one bag of each ratio
	cost_cement=cost_cement*no_ofbagscement;
	cost_sand=cost_sand*no_ofbagssand;
	cost_agg=cost_agg*no_ofbagsaggregates;
	
	double steel_required= build_area*100;
	cout<<"Enter the cost of 1 kg of steel : "<<endl;
	double steel_cost;
	cin>>steel_cost;
	steel_cost=steel_cost*steel_required;//stores the total cost of steel in the cost of one steel
	return cost_of_floor+steel_cost+cost_cement+cost_sand+cost_agg;
}
double calcost_floor(double build_area)
{
	double area_of_marble, marble_cost;
	int no_of_marbles=0;
	cout<<"Enter the area of one marble in meters square : "<<endl;
    cin>>area_of_marble;
    while(area_of_marble <= build_area )
     {
     	area_of_marble += area_of_marble;
     	no_of_marbles++;
	 }
	 cout<<"Enter the cost of one marble : "<<endl;
	 cin>>marble_cost;
	 return marble_cost*no_of_marbles;
    
}
double calcost_boundwall(double len, double width, double boundary)
{
	double per,V_wall,wall_area;
	int number_of_bricks;
	len=len*3.28084;//conversion into feet
	width=width*3.28084;
	//cout<<"Enter the dimensions of one brick in feet(l,w,h): "<<endl;
	//cin>>lbrick>>wbrick>>hbrick;
//	brick_width=wbrick;
	//V_brick= lbrick*wbrick*hbrick;
	per=2*(len+width);
	wall_area= per*boundary;
	V_wall= wall_area*(wbrick); // single brick wall
	number_of_bricks= int(V_wall/V_brick);
	//cout<<"Enter the cost of one brick: ";
	//cin>>cost;
	//cout<<endl;
	//cout<<"Number of bricks are: "<<number_of_bricks<<endl;
	return number_of_bricks*cost;
}
double calcost_boundary(double len, double width, double boundary)
{
	double per,V_wall,wall_area;
	int number_of_bricks;
	len=len*3.28084;//conversion into feet
	width=width*3.28084;
	cout<<"Enter the dimensions of one brick in feet(l,w,h): "<<endl;
	cin>>lbrick>>wbrick>>hbrick;
	brick_width=wbrick;
	V_brick= lbrick*wbrick*hbrick;
	per=2*(len+width);
	wall_area= per*boundary;
	V_wall= wall_area*(2*wbrick); // double brick wall
	number_of_bricks= int(V_wall/V_brick);
	cout<<"Enter the cost of one brick: ";
	cin>>cost;
	cout<<endl;
	cout<<"Number of bricks are: "<<number_of_bricks<<endl;
	return number_of_bricks*cost;
}

void list(){
	cout<<"The following are necesarry rooms and wards in any hospital: "<<endl;
	cout<<"1. Emergency Department (ED)" << endl;
    cout<<"    - Triage Area" << endl;
    cout<<"    - Examination Rooms" << endl;
    cout<<"    - Resuscitation Room" << endl;
    cout<<"    - Waiting Area" << endl;
    cout<<"2. Inpatient Wards" << endl;
    cout<<"    - General Wards" << endl;
    cout<<"    - Intensive Care Unit (ICU)" << endl;
    cout<<"    - Neonatal Intensive Care Unit (NICU)" << endl;
    cout<<"    - Maternity Ward" << endl;
    cout<<"    - Pediatric Ward" << endl;
    cout<<"    - Surgical Ward" << endl;
    cout<<"    - Isolation/Quarantine Ward" << endl;
    cout<<"3. Operating Rooms (OR)" << endl;
    cout<<"    - Surgical Suites" << endl;
    cout<<"    - Pre-operative and Post-operative Rooms" << endl;
    cout<<"4. Outpatient Clinics" << endl;
    cout<<"    - Consultation Rooms" << endl;
    cout<<"    - Diagnostic Rooms" << endl;
    cout<<"5. Radiology and Imaging Department" << endl;
    cout<<"    - X-ray Rooms" << endl;
    cout<<"    - MRI Room" << endl;
    cout<<"    - CT Scan Room" << endl;
    cout<<"    - Ultrasound Room" << endl;
    cout<<"    - Mammography Room" << endl;
    cout<<"6. Laboratory" << endl;
    cout<<"    - Blood Testing Laboratory" << endl;
    cout<<"    - Microbiology Laboratory" << endl;
    cout<<"    - Pathology Laboratory" << endl;
    cout<<"    - Hematology Laboratory" << endl;
    cout<<"7. Pharmacy" << endl;
    cout<<"    - In-house Pharmacy" << endl;
    cout<<"    - Storage Area for Medical Supplies" << endl;
    cout<<"8. Rehabilitation and Therapy Rooms" << endl;
    cout<<"    - Physiotherapy Rooms" << endl;
    cout<<"    - Occupational Therapy Rooms" << endl;
    cout<<"    - Speech Therapy Rooms" << endl;
    cout<<"9. Labor and Delivery Rooms" << endl;
    cout<<"    - Labor Rooms" << endl;
    cout<<"    - Delivery Rooms" << endl;
    cout<<"    - Postpartum Recovery Rooms" << endl;
    cout<<"10. Support and Administrative Areas" << endl;
    cout<<"    - Staff Rooms" << endl;
    cout<<"    - Administrative Offices" << endl;
    cout<<"    - Medical Records Department" << endl;
    cout<<"    - Waiting Areas" << endl;
    cout<<"    - Cafeteria and Kitchen" << endl;
    cout<<"11. Medical Equipment Storage" << endl;
    cout<<"    - General Storage for Medical Equipment" << endl;
    cout<<"    - Sterilization and Disinfection Rooms" << endl;
    cout<<"12. Utilities and Maintenance Areas" << endl;
    cout<<"    - Boiler Room" << endl;
    cout<<"    - Electrical Room" << endl;
    cout<<"    - Water Treatment Facilities" << endl;
    cout<<"13. Other Special Departments" << endl;
    cout<<"    - Dialysis Center" << endl;
    cout<<"    - Blood Bank" << endl;
    cout<<"    - Pain Management Clinic" << endl;
    cout<<"    - Psychiatric Unit or Mental Health Wing" << endl;
}
double cost_building(double build_area)
{ 
    char choice,choice2;
    int no_of_rooms;
    double sum_area=0;
    double height;
    
    cout<<"Enter the height of one floor of the building (in feet) : "<<endl;
    cin>>height;
    double cost_of_boundwall=calcost_boundwall(build_len, build_width, height);//cost of boundary wall of the building
    double cost_of_floor=calcost_floor(build_area);
    double cost_of_ceiling=calcost_ceiling(build_area,cost_of_floor);
    
    cout<<"Do you want to see the list of necesarry rooms and wards in any hospital?(Y/N)"<<endl;
    cin>>choice;
    if(choice=='Y'|| choice=='y' )
    list();
    cout<<"Select the number of wards/rooms you want!!"<<endl;
    cout<<"How many rooms/wards have you selected?"<<endl;
    cin>>no_of_rooms;
    const int size = no_of_rooms;
    double rooms[size] = {};
    int rooms_floor[10]={0};//records the number of rooms on each floor;
    double build_area_remaining = build_area;  // Keeps track of the available area for the current floor
    int current_floor = 0;  // Floor counter//floor 0 is actually floor 1

    cout << "Now just enter the area of all the rooms you have selected one by one:" << endl;
    for (int i = 0; i < no_of_rooms; i++) {
    cin >> rooms[i];

    // Check if adding the current room exceeds the remaining area for the current floor
    if (rooms[i] > build_area_remaining) {
    	//cout<<"Your selected area surpased the total area available."<<endl;
	   	cout<<"There is a need for floor : "<<current_floor+1<<endl;
       // cout << "Room " << i + 1 << " cannot fit on this floor. Moving to the next floor." << endl;

        current_floor++;  // Move to the next floor
        build_area_remaining = build_area;  // Reset available area for the new floor
    }
      rooms_floor[current_floor]++;//roomsfloor[0] is the ground floor
    // Deduct room area from the current floor's available area
    build_area_remaining -= rooms[i];
}

// Output results
cout << "Total number of floors required: " << current_floor + 1 << endl;
const int size1= current_floor+1;  //declares size of array as number of floors
int no_ofwalls[size1]={0};
for(int i=0; i<current_floor; i++){
     cost_of_boundwall+=cost_of_boundwall;//multiplies the cost of one bound wall with floors 
     cost_of_ceiling+=cost_of_ceiling;//multiplies the cost of one cieling with floors
 }

for (int j=0; j< size; j++)
for(int i=0; i<rooms_floor[j]-2; i++ )//number of partition walls are 2 less than no of rooms
    no_ofwalls[j]+=1; //calculates number of walls on jth floor
 cout<<"How wide should be the corridor : "<<endl;
double corridor_width;
cin>>corridor_width;
double corridorwall_length=0;
double cost_corridorwalls=calcost_corridorwalls(build_len,height);
for(int i=0; i<=current_floor; i++){//in this case we are also calculating the ground floor
     cost_corridorwalls+=cost_corridorwalls;
     corridorwall_length+=corridorwall_length+(2*build_len);//total length of corridor walls
}
 double wall_length=build_width-corridor_width;
 double totalwallslength=1;
 double cost_partitionwall=calcost_corridorwalls(wall_length,height);//cost of one partition wall
 for(int j=0; j<=current_floor; j++){//in this case we are also calculating the ground floor
     for(int i=0; i<no_ofwalls[j]; i++)
         cost_partitionwall+=cost_partitionwall;//cost of one partition wall is extra
         cost_of_floor+=cost_of_floor;//total length of partition walls
}
  double total_cost=cost_corridorwalls+cost_of_boundwall+cost_of_ceiling+cost_partitionwall+cost_of_floor;
  return total_cost;
}


int main()
{
	double area, boundary_wall, len, width, left_area, build_area;
	double left_len, left_width;
	cout<<"Enter the dimensions of the Rectangular area available in meters: "<<endl;
	cin>>len>>width;
	area=len*width;	
	cout<<"Enter the height of boundary wall in feet: "<<endl;
	cin>>boundary_wall;//this is height
	double boundary_cost = calcost_boundary(len,width,boundary_wall);
	cout<<boundary_cost<<endl;
	cout<<"Enter the dimensions of the left area for parking and greenery?(in meters) "<<endl;
	cin>>left_len>>left_width;
	left_area=left_len*left_width;
	left_area= left_area+(2*brick_width);//excludes the left area and double brick width
	build_area=area-left_area;
	build_len=len-left_len;//calculates the length of available area
	build_width=width-left_width;//calculates the width of available area
	double cost=cost_building(build_area);
	cout<<"The total cost of the building is : "<<cost<<endl;
	
		return 0;
}