//
//  main.c
//  A4
//
//  Created by xuwen nie on 15/10/14.
//  Copyright © 2015年 xuwen nie. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//make struct team hold the id,wins,lose,tie,score,losescore
struct team{
    int teamid;
    int teamwin;
    int teamlose;
    int teamtie;
    int teamscore;
    int teamlosescore;
    int show;
};
//make a struct arry team to store all the teams and create newteams array to store the struct team after sort it.
struct team teams[20];
struct team newteams[20];
//initialize all elements in teams[20]
void initialize(){
    for(int i = 0;i<20;i++){
       //initialize the teams
        teams[i].teamid = 0;
        teams[i].teamwin = 0;
        teams[i].teamlose = 0;
        teams[i].teamtie = 0;
        teams[i].teamscore = 0;
        teams[i].teamlosescore = 0;
        teams[i].show = 0;
        //initialize the newteams
        newteams[i].teamid = 0;
        newteams[i].teamwin = 0;
        newteams[i].teamlose = 0;
        newteams[i].teamtie = 0;
        newteams[i].teamscore = 0;
        newteams[i].teamlosescore = 0;
        newteams[i].show = 0;
    }
}
//add method,once find the team or create a new team,put all the elements in the struct array
//I combined find and add method together
void add_team(int a,int b,int c,int d){
 
 if( teams[a-1].teamid == 0 || teams[a-1].teamid == a){
     //increase show time
     teams[a-1].show++;
     
     teams[a-1].teamid = a;
     teams[a-1].teamscore += c;
     teams[a-1].teamlosescore += d;
     if(c>d){
         teams[a-1].teamwin ++;
     }else if(c<d){
         teams[a-1].teamlose ++;
     }else{
         teams[a-1].teamtie ++;
     }
 }
 
 if(teams[b-1].teamid == 0 || teams[b-1].teamid == b){
     //increase show time
     teams[b-1].show ++;
     
     teams[b-1].teamid = b;
     teams[b-1].teamscore += d;
     teams[b-1].teamlosescore += c;
     if(d>c){
         teams[b-1].teamwin ++;
     }else if(d<c){
        teams[b-1].teamlose ++;
     }else{
        teams[b-1].teamtie ++;
     }
    }

}
//compare method once i findout the largest one I copy it into new struct array newteams and delete it in original one in teams.
void sort(){
    for(int j = 0;j<20;j++){
        for(int i = 0;i<20;i++){
            //compare win
            if(newteams[j].teamwin<teams[i].teamwin){
                newteams[j].teamid = teams[i].teamid;
                newteams[j].teamwin = teams[i].teamwin;
                newteams[j].teamlose = teams[i].teamlose;
                newteams[j].teamtie = teams[i].teamtie;
                newteams[j].teamscore = teams[i].teamscore;
                newteams[j].teamlosescore = teams[i].teamlosescore;
            }
            //compare tie
     /*       else if(newteams[j].teamwin == teams[i].teamwin){
                if(newteams[j].teamtie<teams[i].teamtie){
                    newteams[j].teamid = teams[i].teamid;
                    newteams[j].teamwin = teams[i].teamwin;
                    newteams[j].teamlose = teams[i].teamlose;
                    newteams[j].teamtie = teams[i].teamtie;
                    newteams[j].teamscore = teams[i].teamscore;
                }
                //compare score
                else if(newteams[j].teamtie == teams[i].teamtie){
                    if(newteams[j].teamscore<teams[i].teamscore){
                        newteams[j].teamid = teams[i].teamid;
                        newteams[j].teamwin = teams[i].teamwin;
                        newteams[j].teamlose = teams[i].teamlose;
                        newteams[j].teamtie = teams[i].teamtie;
                        newteams[j].teamscore = teams[i].teamscore;
                    }
                        //compare score difference
                    else if(newteams[j].teamscore == teams[i].teamscore){
                        if(newteams[j].teamlosescore<teams[i].teamlosescore){
                            newteams[j].teamid = teams[i].teamid;
                            newteams[j].teamwin = teams[i].teamwin;
                            newteams[j].teamlose = teams[i].teamlose;
                            newteams[j].teamtie = teams[i].teamtie;
                            newteams[j].teamscore = teams[i].teamscore;
                        }
                        //compare showtimes
                        else if(newteams[j].teamlosescore == teams[i].teamlosescore){
                            if(newteams[j].show<teams[i].show){
                                newteams[j].teamid = teams[i].teamid;
                                newteams[j].teamwin = teams[i].teamwin;
                                newteams[j].teamlose = teams[i].teamlose;
                                newteams[j].teamtie = teams[i].teamtie;
                                newteams[j].teamscore = teams[i].teamscore;
                            }
                            //compare number order
                            else if(newteams[j].show==teams[i].show){
                                if(newteams[j].teamid<newteams[i].teamid){
                                    newteams[j].teamid = teams[i].teamid;
                                    newteams[j].teamwin = teams[i].teamwin;
                                    newteams[j].teamlose = teams[i].teamlose;
                                    newteams[j].teamtie = teams[i].teamtie;
                                    newteams[j].teamscore = teams[i].teamscore;
                                }
                            }
                        }
                    }
                }
            }  */
        
    //delete the one which is already copied in to newteams
            //once find the same id delete all elements
        }
    }
}

//main method
int main() {
    initialize();
    printf("Enter");
    int a=1,b=1,c=1,d=1;
    while(a!=0 || b!=0 || c!=0 || d!=0){
        scanf("%d%d%d%d",&a,&b,&c,&d);

        add_team(a,b,c,d);
    
    }
    sort();
    
    int i = 0;
    while(teams[i].teamid!=0){
        printf("%3d%3d%3d%3d%3d%3d",newteams[i].teamid,newteams[i].teamwin,newteams[i].teamlose,newteams[i].teamtie,newteams[i].teamscore,newteams[i].teamlosescore);
        printf("\n");
        i++;
    }
    
    return 0;
}

 


