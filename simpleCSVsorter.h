#include <stdlib.h>

typedef struct{
  void *data;
  char[] *row;
  Node *next;
}Node;

/*int vals[28][2]={
  {"color", "String"},
  {"director_name", "String"},
  {"num_critic_for_reviews", "Numeric"},
  {"duration"}
  int director_facebook_likes
  int actor_3_facebook_likes;
  char actor_2_name[];
  int actor_1_facebook_likes;
  int gross;
  char genres[];
  char actor_1_name[];
  char movie_title[];
  int num_voted_users;
  int cats_total_facebook_likes;
  char actor_3_name[];
  int facenumber_in_poster;
  char plot_keywords[];
  char movie_imdb_link[];
  int num_user_for_reviews;
  char language[];
  char country[];
  char content_ration[];
  int budget;
  int title_year;
  int actor_2_facebook_likes;
  int imdb_score;
  int aspect_ratio;
  int movie_facebook_likes;
} */

void readfile();
char *remove_leading_spaces(char* line);
int columnNum(char *row, char *col);
char *tokenizer(int col, char *line);
String Node* SortedMerge( struct Node* a, struct Node* b);
void print(struct Node* a);

