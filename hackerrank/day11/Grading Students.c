int* gradingStudents(int grades_count, int* grades, int* result_count) {
for(int i=0;i<grades_count;i++){
    if(grades[i]>=38){
     if(grades[i]%5>2){
         grades[i]+=5-(grades[i]%5);
     }   
    }
}
*result_count=grades_count;
return grades;
}