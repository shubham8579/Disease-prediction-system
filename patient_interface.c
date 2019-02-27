#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

int main() 
{ 
int rs;							//running status 
do{

	int k;
	printf(" 1.Signup \n");
	printf(" 2.Login \n");
	printf("enter your input:\t\n");
	scanf("%d",&k);
	
	
	switch (k)
	{
		case 1: ;
	
			long int num;
			//long int *p = &num;				// to use fwrite function
			
			char fname[10];					//to store file name 
   			FILE *rg = fopen("regno.txt","r"); //to read registration nmber file
    
    		fscanf(rg,"%li",&num);
    		
			sprintf(fname,"%li.txt",num);		//num value stored in fname pointer in string format 
    
    		num++;
    								//printf("%s\n",fname);									 //fwrite(p , 1 , sizeof(long int) , rg ); // to overwrite the registeration number with updated one in "regno.txt" fi
    		fclose(rg);       		//file closed
    		
    		rg = fopen("regno.txt","w");
    		fprintf(rg,"%li",num);
    		fclose(rg);     
    		//strcat(fname,".txt");
    		printf("%s Please note your registration number\n",fname);
    		num--;
    		FILE *fp = fopen(fname,"w+");
    
    
    		char s1[20],s2[20],s3[20],s4[20];
	
			fputs("\n Registration number: ",fp);
			fprintf(fp,"%li",num);
	
	
			printf("enter name :");;
			gets(s1);
			gets(s1);
			fputs("\n NAME: ",fp);
			fputs(s1,fp);
	
			printf("\nenter mobile :");
			gets(s2);
			fputs("\n MOBILE: ",fp);
			fputs(s2,fp);
	
			printf("Gender(M/F) :");
			gets(s3);
			fputs("\n GENDER: ",fp);
			fputs(s3,fp);
	
			printf("enter your age :");
			gets(s4);
			fputs("\n AGE: ",fp);
			fputs(s4,fp);
	
			fclose(fp);
			return 0;
		
		case 2:
			
			printf("enter your registration number");
			long int number;
			scanf("%li",&number);
			
			char regno[10];			//to open the  file of patient if it exist
			
			sprintf(regno,"%li.txt",number);
			FILE *fs = fopen(regno,"r");
		
			if(fs == NULL)
			{
				printf("patient not found\nplease sign up first.");
				fclose(fs);
				return 1;
			}				
			else
			{
				char n1[200];
				char n2[8];
				char n3[20];
				fgets(n1,200,fs);
				fgets(n1,200,fs);
				fgets(n2,8,fs);
				fgets(n3,20,fs);
				printf("\nWELCOME Mr.%s",n3);
				fclose(fs);
				FILE *fs = fopen(regno,"a");	//file open to enter symptoms and disease
				int i;
				printf("\nFollowing is the List of symptoms to choose from :-\n");
				char symp[30][50]; 
				
				strcpy(symp[1],"chills");	
				strcpy(symp[2],"cough");
				strcpy(symp[3],"fever");
				strcpy(symp[4],"fatigue");	
				strcpy(symp[5],"sweating");
				strcpy(symp[6],"chest pain");
				strcpy(symp[7],"dehydration");
				strcpy(symp[8],"yellow mucus");
				strcpy(symp[9],"pain in eyes");
				strcpy(symp[10],"rash on skin");
				strcpy(symp[11],"swallon gland");
				strcpy(symp[12],"abdominal pain");
				strcpy(symp[13],"fast breathing");
				strcpy(symp[14],"purplish skin color");
				strcpy(symp[15],"High fever upto 104F");
				strcpy(symp[16],"fever for short durations");
				strcpy(symp[17],"watery stool/Blood in stool");
			
			
				for( i=1;i<18;i++)
				{
					printf("%d.%s\n",i,symp[i]);										//showing all the symptoms on the user screen
				}
				
				char sympm[6][50];				//malaria
				char sympd[6][50];				//dengue
				char sympp[7][50];				//pneumonia
				char sympdi[6][50];				//diarrhea
				
				strcpy(sympm[1],"fever for short durations");				//entering symptoms of malaria in structure array
				strcpy(sympm[2],"sweating");
				strcpy(sympm[3],"chills");
				strcpy(sympm[4],"chest pain");
				strcpy(sympm[5],"cough");
				
				strcpy(sympd[1],"High fever upto 104F");			//entering symptoms of dengue in structure array
				strcpy(sympd[2],"pain in eyes");
				strcpy(sympd[3],"rash on skin");
				strcpy(sympd[4],"swallon gland");
				strcpy(sympd[5],"cough");
				
				strcpy(sympp[1],"yellow mucus");
				strcpy(sympp[2],"cough");
				strcpy(sympp[3],"fast breathing");
				strcpy(sympp[4],"fatigue");
				strcpy(sympp[5],"sweating");
				strcpy(sympp[6],"purplish skin color");
				
				strcpy(sympdi[1],"watery stool/Blood in stool");
				strcpy(sympdi[2],"abdominal pain");
				strcpy(sympdi[3],"fever");
				strcpy(sympdi[4],"dehydration");
				
				
				int k,mflag = 0,dflag = 0,pflag = 0,diflag = 0;							//flag variables to count the score of disease
				int j,s;
				fputs("\n\nSymptoms : ",fs);
				printf("\nHow many symptoms you wan't enter(ENTER ATLEAST 5 SYMPTOMS FOR ACCURACY):\t");
				scanf("%d",&s);
				
				for(j=1;j<=s;j++)
				{
					printf("enter your symptom index number from which you are suffering:\t");
					scanf("%d",&k);									//taking input of  symptoms
					fputs(symp[k],fs);
					fputs(", ",fs);
					for(i=1;i<=5;i++)								//comparing to malaria
					{
						if(strcmp(symp[k],sympm[i]) == 0)
							mflag += 1;
						else
							continue;	
					
					}
					
					for(i=1;i<=5;i++)												//comparing to malaria
					{
						if(strcmp(symp[k],sympd[i]) == 0)
							dflag += 1;
						else
							continue;	
					
					}
					
					for(i=1;i<=6;i++)												//comparing to malaria
					{
						if(strcmp(symp[k],sympp[i]) == 0)
							pflag += 1;
						else
							continue;	
					
					}
					
					for(i=1;i<=4;i++)												//comparing to malaria
					{
						if(strcmp(symp[k],sympdi[i]) == 0)
							diflag += 1;
						else
							continue;	
					
					}
				}
				//printf("%d\n",mflag);
				//printf("%d\n",dflag);
			
				float mprob = (mflag*100)/s;
				float dprob = (dflag*100)/s;
				float pprob = (pflag*100)/s;
				float diprob = (diflag*100)/s;
				
				fputs("\n\nDisease predicted: ",fs);
				if(mflag > dflag)
				{
					if(mflag > pflag)
					{
						if(mflag > diflag)
						{
							printf("\nThere are %f'%%' chances you are suffering from MALARIA,\nBut Don't WORRY\n",mprob);
							printf("\nCause of Disease : Anopheles mosquito transmits it to humans.\n");
							printf("\nRemedies :\n1.Apple Vinegar.\n2.Ginger Water\n3.Cinnamon and Honey Water\n4.Fresh Juice\n5.Herbal Tea and Milk\n");
							if(mprob > 50.0)
							{
								printf("As your chances are quite high you are storingly adviced to consult a Doctor\n");
								printf("\n\t\tGET WELL SOON %s",n3);
							}
							else 
								printf("\n\t\tGET WELL SOON %s",n3);
							fputs("MALARIA",fs);
						}
						else
						{
							printf("\nThere are %f'%%' chances you are suffering from DIARRHEA,\nBut Don't WORRY\n",diprob);
							printf("\nCause of Disease : Gluten intolerance, Lactose intolerance, Chronic bowel infection .\n");
							printf("\nRemedies :\n1.Avoid caffeine, dairy products, and greasy, high fibre, or sugary foods.\n2.Placing a hot water bottle or wheat pack on your stomach, or taking paracetamol, may provide some relief from abdominal cramps.\n3.Apply zinc and castor oil ointment or a barrier cream to affected areas if you, or your child, develops a rash (like nappy rash) from the diarrhoea.\n");
							if(diprob > 50.0)
							{
								printf("As your chances are quite high you are storingly adviced to consult a Doctor\n");
								printf("\n\t\tGET WELL SOON %s",n3);
							}
							else 
								printf("\n\t\tGET WELL SOON %s",n3);
							fputs("DIARRHEA",fs);
						}
					}
					else
					{
						if(pflag > diflag)
						{
							printf("\nThere are %f'%%' chances you are suffering from pneumonia,\nBut Don't WORRY\n",pprob);
							printf("\nCause of Disease : Bacteria and viruses are the main causes of pneumonia,They can be passed on through coughing and sneezing, or spread onto shared objects through touch.\n");
							printf("\nRemedies :\n1.Do a saltwater gargle.\n2.Drink hot peppermint tea.\n3.Eat carrots.\n4.Apply 2-3 drops of camphor oil to chest & back.\n5.Take staem inhalation(best with vicks vaporub).");
							if(pprob > 50.0)
							{
								printf("As your chances are quite high you are storingly adviced to consult a Doctor\n");
								printf("\n\t\tGET WELL SOON %s",n3);
							}
							else 
								printf("\n\t\tGET WELL SOON %s",n3);
							fputs("PNEUMONIA",fs);
						}
						else
						{
							printf("\nThere are %f'%%' chances you are suffering from DIARRHEA,\nBut Don't WORRY\n",diprob);
							printf("\nCause of Disease : Gluten intolerance, Lactose intolerance, Chronic bowel infection .\n");
							printf("\nRemedies :\n1.Avoid caffeine, dairy products, and greasy, high fibre, or sugary foods.\n2.Placing a hot water bottle or wheat pack on your stomach, or taking paracetamol, may provide some relief from abdominal cramps.\n3.Apply zinc and castor oil ointment or a barrier cream to affected areas if you, or your child, develops a rash (like nappy rash) from the diarrhoea.\n");
							if(diprob > 50.0)
							{
								printf("As your chances are quite high you are storingly adviced to consult a Doctor\n");
								printf("\n\t\tGET WELL SOON %s",n3);
							}
							else 
								printf("\n\t\tGET WELL SOON %s",n3);
							fputs("DIARRHEA",fs);
							
					}
				}}
				else
				{
					if(dflag > pflag)
					{
						if(dflag > diflag)
						{
							printf("\nThere are %f'%%' chances you are suffering from DENGUE, \n But Don't WORRY\n",dprob);
							printf("\nCause of Disease : mosquitoes of the species Aedes aegypti, and sometimes also by Aedes albopictus.\n ");
							printf("\nRemedies : \n1.Giloy: It is a Ayurveda hurb that helps in protects your body against infections, strengthen the immune system, and maintain metabolic rate.\n Giloy herbal drink is prepared by boiling the stems.\n2.Drink orange juice.\n3.Juice of papaya leaves\n4.Drink water as much as you can.\n");
							if(dprob > 50.0)
							{
								printf("As your chances are quite high you are storingly adviced to consult a Doctor\n");
								printf("\n\t\tGET WELL SOON %s",n3);
							}
							else 
								printf("\n\t\tGET WELL SOON %s",n3);
							fputs("DENGUE",fs);
						}
						else
						{
							printf("\nThere are %f'%%' chances you are suffering from DIARRHEA,\n But Don't WORRY\n",diprob);
							printf("\nCause of Disease : Gluten intolerance, Lactose intolerance, Chronic bowel infection .\n");
							printf("\nRemedies :\n1.Avoid caffeine, dairy products, and greasy, high fibre, or sugary foods.\n2.Placing a hot water bottle or wheat pack on your stomach, or taking paracetamol, may provide some relief from abdominal cramps.\n3.Apply zinc and castor oil ointment or a barrier cream to affected areas if you, or your child, develops a rash (like nappy rash) from the diarrhoea.\n");
							if(diprob > 50.0)
							{
								printf("As your chances are quite high you are storingly adviced to consult a Doctor\n");
								printf("\n\t\tGET WELL SOON %s",n3);
							}
							else 
								printf("\n\t\tGET WELL SOON %s",n3);
							fputs("DIARRHEA",fs);
						}
					}
					else
					{
						if(pflag > diflag)
						{
							printf("\nThere are %f'%%' chances you are suffering from pneumonia,\n But Don't WORRY here is the SOLUTION\n",pprob);
							printf("\nCause of Disease : Bacteria and viruses are the main causes of pneumonia,They can be passed on through coughing and sneezing, or spread onto shared objects through touch.\n");
							printf("\nRemedies :\n1.Do a saltwater gargle.\n2.Drink hot peppermint tea.\n3.Eat carrots.\n4.Apply 2-3 drops of camphor oil to chest & back.\n5.Take staem inhalation(best with vicks vaporub).");
							if(pprob > 50.0)
							{
								printf("As your chances are quite high you are storingly adviced to consult a Doctor\n");
								printf("\n\t\tGET WELL SOON %s",n3);
							}
							else 
								printf("\n\t\tGET WELL SOON %s",n3);
							fputs("PNEUMONIA",fs);
						}
						else
						{
							printf("\nThere are %f'%%' chances you are suffering from DIARRHEA,\n But Don't WORRY here is the SOLUTION",diprob);
							printf("\nCause of Disease : Gluten intolerance, Lactose intolerance, Chronic bowel infection .\n");
							printf("\nRemedies :\n1.Avoid caffeine, dairy products, and greasy, high fibre, or sugary foods.\n2.Placing a hot water bottle or wheat pack on your stomach, or taking paracetamol, may provide some relief from abdominal cramps.\n3.Apply zinc and castor oil ointment or a barrier cream to affected areas if you, or your child, develops a rash (like nappy rash) from the diarrhoea.\n");
							if(diprob > 50.0)
							{
								printf("As your chances are quite high you are storingly adviced to consult a Doctor\n");
								printf("\n\t\tGET WELL SOON %s",n3);
							}
							else 
								printf("\n\t\tGET WELL SOON %s",n3);
							fputs("DIARRHEA",fs);
						}
					}
					
					
				}
				//fclose(fs);
			}
			
					
	}
printf("\n press 1 for exit & 0 for not ");
scanf("%d",&rs);		
	
}
while(rs == 0);  			//do-while loop
	
return 1;	
} 


