/*
    Programmer: Grant Ogden
    Date: 2/14/2019
    Project: C File Creator
    Reason: To be lazy and have a program create my files for me
*/
#ifndef C_FILE_CREATOR
#define C_FILE_CREATOR
#define MAX_FILE_PATH_LENGTH (260)
#define MAX_FILE_NAME_LENGTH (50)



/*
 * FUNCTION:    
 * ARGUEMENTS:  
 * RETURN:      
 * NOTES:   
 */
extern int write_files(char * fileName);

/*
 * FUNCTION:
 * ARGUEMENTS:
 * RETURN:
 * NOTES:
 */
extern int write_c_files();

/*
 * FUNCTION:
 * ARGUEMENTS:
 * RETURN:
 * NOTES:
 */
extern int write_h_files(char * fileName);

/*
 * FUNCTION:
 * ARGUEMENTS:
 * RETURN:
 * NOTES:
 */
extern int open_file(char * filePath,char * fileName);

/*
 * FUNCTION:
 * ARGUEMENTS:
 * RETURN:
 * NOTES:
 */
extern int create_project(char * filePath,char * fileName);

#endif