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
 * FUNCTION:    Writes the Main.c file for the project.
 * ARGUEMENTS:  VOID
 * RETURN:      0 on success.
 * NOTES:       VOID
 */
extern int write_main_c_file();

/*
 * FUNCTION:    Writes both <fileName>.h and <fileName>.c files for the
 *                  project. 
 * ARGUEMENTS:  VOID
 * RETURN:      0 on success.
 * NOTES:       VOID
 */
extern int write_h_files();

/*
 * FUNCTION:    Opens the file pointer so that the files can be written
 *                  into.
 * ARGUEMENTS:  char fileType: Takes a char specifier telling it which file
 *                  to open.
 * RETURN:      0 on success.
 *              ERR_FILE_IO (-2) if the file wasn't properly opened.
 * NOTES:       'm' opens Main.c
 *              'h' opens <fileName>.h
 *              'c' opens <fileName>.c
 */
extern int open_write_file(char fileType);

/*
 * FUNCTION:    Opens the file pointer so that the files can be written
 *                  into.
 * ARGUEMENTS:  char fileType: Takes a char specifier telling it which file
 *                  to open.
 * RETURN:      0 on success.
 *              ERR_FILE_IO (-2) if the file wasn't properly opened.
 * NOTES:       'm' opens DefaultMain.tmp
 *              'h' opens DefaultHeaderH.tmp
 *              'c' opens DefaultHeaderC.tmp
 */
extern int open_read_file(char fileType);

/*
 * FUNCTION:    The main function of CFileCreator.c. It creates the
 *                  directory and then creates all the corresponding
 *                  files to be placed in it.
 * ARGUEMENTS:  char *filePath: Takes the file path for the directory
 *                  to make the project in.
 *              char *fileName: Takes the file name for the project
 *                  folder and the header file names.
 * RETURN:      0 on success.
 *              ERR_NULL_POINTER (-1) if either of the pointers are NULL
 *              ERR_FILE_PATH_LENGTH (-3) if the filePath is to long
 * NOTES:
 */
extern int create_project(char * filePath,char * fileName);

/*
 * FUNCTION:    Takes the filePath and fileName and save them in globals
 *                  so that they are accessible by all other functions in
 *                  CFileCreator.c.
 * ARGUEMENTS:  char *filePath: Takes the file path for the directory
 *                  to make the project in.
 *              char *fileName: Takes the file name for the project
 *                  folder and the header file names.
 * RETURN:      0 on success.
 * NOTES:
 */
extern int save_file_path(char * filePath,char * fileName);

#endif