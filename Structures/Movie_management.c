// Write a program that use a structure to hold information about movies, such as title,
// genre, director, release year, and rating. Write a program that allows users to add new
// movies, search for movies by genre, and display all movie details.

#include <stdio.h>
#include <string.h>

// Define the structure for movie information
typedef struct {
    char title[100];
    char genre[50];
    char director[50];
    int releaseYear;
    float rating;
} Movie;

// Function to add a new movie
void addMovie(Movie *movie) {
    getchar();  // Clear the newline character left by previous input
    printf("Enter movie title: ");
    fgets(movie->title, sizeof(movie->title), stdin);
    movie->title[strcspn(movie->title, "\n")] = '\0'; // Remove newline

    printf("Enter movie genre: ");
    fgets(movie->genre, sizeof(movie->genre), stdin);
    movie->genre[strcspn(movie->genre, "\n")] = '\0'; // Remove newline

    printf("Enter director: ");
    fgets(movie->director, sizeof(movie->director), stdin);
    movie->director[strcspn(movie->director, "\n")] = '\0'; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &movie->releaseYear);

    printf("Enter movie rating (out of 10): ");
    scanf("%f", &movie->rating);

    printf("Movie added successfully!\n");
}

// Function to display movie details
void displayMovieDetails(Movie movie) {
    printf("\n--- Movie Details ---\n");
    printf("Title: %s\n", movie.title);
    printf("Genre: %s\n", movie.genre);
    printf("Director: %s\n", movie.director);
    printf("Release Year: %d\n", movie.releaseYear);
    printf("Rating: %.1f/10\n", movie.rating);
}

// Function to search movies by genre
void searchMoviesByGenre(Movie movies[], int count, char genre[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            displayMovieDetails(movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in the genre: %s\n", genre);
    }
}

int main() {
    Movie movies[100];  // Array to store up to 100 movies
    int movieCount = 0;
    int choice;
    char genreSearch[50];

    while (1) {
        // Display menu
        printf("\n--- Movie Management System ---\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new movie
                addMovie(&movies[movieCount]);
                movieCount++;
                break;
            case 2:
                // Search movies by genre
                getchar();  // Clear the newline character
                printf("Enter genre to search: ");
                fgets(genreSearch, sizeof(genreSearch), stdin);
                genreSearch[strcspn(genreSearch, "\n")] = '\0';  // Remove newline
                searchMoviesByGenre(movies, movieCount, genreSearch);
                break;
            case 3:
                // Display all movies
                if (movieCount == 0) {
                    printf("No movies added yet.\n");
                } else {
                    for (int i = 0; i < movieCount; i++) {
                        displayMovieDetails(movies[i]);
                    }
                }
                break;
            case 4:
                // Exit the program
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
