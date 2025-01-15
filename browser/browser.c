#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RED_COMMAND       "\033[31m"
#define BLUE_COMMAND      "\033[34m"
#define GREEN_COMMAND     "\033[32m"
#define BOLD_COMMAND      "\033[1m"
#define ITALIC_COMMAND    "\033[3m"
#define UNDERLINE_COMMAND "\033[4m"
#define RESET_COMMAND     "\033[0m"

char* strdup(const char* s);

enum ElementType { DIV, IMG, H, P };

typedef struct element_t {
    enum ElementType type;
    int w, h;
    enum { start, center, end, space_evenly } align_items, justify_content;
    enum { row, column } direction;
    struct element_t** children;
    int children_count;
    char* src, * content;
    int em, i, u;
    enum color_t { NONE, RED, BLUE, GREEN } color;
} Element;

char* skipSpaces(char* p) {
    while (*p == ' ' || *p == '\n' || *p == '\t') p++;
    return p;
}

char* skipEndTag(char* p) {
    if (strncmp(p, "</h>", 4) == 0) return p + 4;
    if (strncmp(p, "</p>", 4) == 0) return p + 4;
    if (strncmp(p, "</img>", 6) == 0) return p + 6;
    return p;
}

Element* createElement(enum ElementType type, Element* fa) {
    Element* element = calloc(1, sizeof(Element));
    element->type = type;
    fa->children = realloc(fa->children, (fa->children_count + 1) * sizeof(Element*));
    fa->children[fa->children_count++] = element;
    if (type == DIV) element->w = element->h = -1;
    return element;
}

char* parseAttributes(char* p, Element* ele) {
    while (1) {
        p = skipSpaces(p);
        if (*p == '>') return p + 1;
        if (strncmp(p, "i", 1) == 0) ele->i = 1;
        else if (strncmp(p, "u", 1) == 0) ele->u = 1;
        else if (strncmp(p, "em", 2) == 0) ele->em = 1, p++;
        else if (strncmp(p, "w=\"", 3) == 0) sscanf(p, "w=\"%d\"", &ele->w), p = strchr(p, '\"');
        else if (strncmp(p, "h=\"", 3) == 0) sscanf(p, "h=\"%d\"", &ele->h), p = strchr(p, '\"');
        else if (strncmp(p, "width=\"", 7) == 0) sscanf(p, "width=\"%d\"", &ele->w), p = strchr(p, '\"');
        else if (strncmp(p, "color=\"", 7) == 0) {
            p += 7;
            if (strncmp(p, "red", 3) == 0) ele->color = RED, p += 3;
            else if (strncmp(p, "blue", 4) == 0) ele->color = BLUE, p += 4;
            else ele->color = GREEN, p += 5;
        }
        else if (strncmp(p, "align-items=\"", 13) == 0) {
            p += 13;
            if (strncmp(p, "start", 5) == 0) ele->align_items = start, p += 5;
            else if (strncmp(p, "center", 6) == 0) ele->align_items = center, p += 6;
            else if (strncmp(p, "end", 3) == 0) ele->align_items = end, p += 3;
            else ele->align_items = space_evenly, p += 12;
        }
        else if (strncmp(p, "justify-content=\"", 17) == 0) {
            p += 17;
            if (strncmp(p, "start", 5) == 0) ele->justify_content = start, p += 5;
            else if (strncmp(p, "center", 6) == 0) ele->justify_content = center, p += 6;
            else if (strncmp(p, "end", 3) == 0) ele->justify_content = end, p += 3;
            else ele->justify_content = space_evenly, p += 12;
        }
        else if (strncmp(p, "direction=\"", 11) == 0) {
            p += 11;
            if (strncmp(p, "row", 3) == 0) ele->direction = row, p += 3;
            else ele->direction = column, p += 6;
        }
        else if (strncmp(p, "src=\"", 5) == 0) {
            p += 5;
            char* q = malloc(10010 * sizeof(char));
            int len = 0;
            while (*p != '\"') q[len++] = *p++;
            q[len] = '\0', ele->src = strdup(q);
            free(q);
        }
        p++;
    }
}

char* parseContent(char* p, Element* ele) {
    char* q = malloc(10010 * sizeof(char));
    int len = 0;
    while (*p != '<') q[len++] = *p++;
    q[len] = '\0';
    ele->content = strdup(q);
    ele->h = 1, ele->w = len;
    if (ele->type == H)
        for (int i = 0; i < len; i++) ele->content[i] = toupper(ele->content[i]);
    free(q);
    return p;
}

void analyse(Element* root) {
    Element* cur = root, * stk[150];
    char* html = malloc(10010 * sizeof(char)), ch;
    int len = 0, stk_size = 0;
    stk[stk_size++] = root;
    while ((ch = getchar()) != EOF) html[len++] = ch;
    html[len] = '\0';
    char* p = html;
    while (*p) {
        p = skipSpaces(p);
        if (strncmp(p, "</div>", 6) == 0) {
            p += 6;
            cur = stk[--stk_size - 1];
        }
        p = skipEndTag(p);
        if (*p == '<') {
            if (strncmp(p + 1, "div", 3) == 0) {
                p += 4;
                Element* element = createElement(DIV, cur);
                stk[stk_size++] = element, cur = element;
                p = parseAttributes(p, element);
            }
            else if (strncmp(p + 1, "img", 3) == 0) {
                p += 4;
                Element* element = createElement(IMG, cur);
                p = parseAttributes(p, element);
            }
            else if (strncmp(p + 1, "h", 1) == 0) {
                p += 2;
                Element* element = createElement(H, cur);
                p = parseAttributes(p, element);
                p = parseContent(p, element);
            }
            else if (strncmp(p + 1, "p", 1) == 0) {
                p += 2;
                Element* element = createElement(P, cur);
                p = parseAttributes(p, element);
                p = parseContent(p, element);
            }
        }
    }
    free(html);
}

char output[12][55];
typedef struct format_t {
    enum color_t color;
    int u, i, em;
    int reset;
} Format;
Format format[12][55];

void render(Element* element, int row, int col);

void renderDiv(Element* element, int r, int c) {
    if (element->direction == row) {
        int x = r, y = c, h = 0;
        for (int i = 0; i < element->children_count; i++) h += element->children[i]->h;
        int space = (element->h - h) / (element->children_count + 1);
        if (element->align_items == center) x = r + (element->h - h) / 2;
        if (element->align_items == end) x = r + element->h - h;
        for (int i = 0; i < element->children_count; i++) {
            if (element->align_items == space_evenly) x += space;
            if (element->justify_content == center || element->justify_content == space_evenly)
                y = c + (element->w - element->children[i]->w) / 2;
            if (element->justify_content == end) y = c + element->w - element->children[i]->w;
            render(element->children[i], x, y);
            x += element->children[i]->h;
        }
    }
    else {
        int x = r, y = c, w = 0;
        for (int i = 0; i < element->children_count; i++) w += element->children[i]->w;
        int space = (element->w - w) / (element->children_count + 1);
        if (element->justify_content == center) y = c + (element->w - w) / 2;
        if (element->justify_content == end) y = c + element->w - w;
        for (int i = 0; i < element->children_count; i++) {
            if (element->justify_content == space_evenly) y += space;
            if (element->align_items == center || element->align_items == space_evenly)
                x = r + (element->h - element->children[i]->h) / 2;
            if (element->align_items == end) x = r + element->h - element->children[i]->h;
            render(element->children[i], x, y);
            y += element->children[i]->w;
        }
    }
}

void render(Element* element, int row, int col) {
    if (element->type == DIV) renderDiv(element, row, col);
    if (element->type == IMG) {
        char* pos = element->src;
        int x = row, y = col, count = 0;
        while (*pos) {
            output[x][y] = *pos++, format[x][y].color = NONE, count++;
            format[x][y].u = format[x][y].i = format[x][y].em = 0;
            if (count == element->w) x++, y = col, count = 0;
            else y++;
        }
    }
    if (element->type == H || element->type == P) {
        format[row][col].color = element->color;
        format[row][col].u = element->u, format[row][col].i = element->i, format[row][col].em = element->em;
        char* pos = element->content;
        int x = row, y = col;
        while (*pos) output[x][y++] = *pos++;
        if (element->color != NONE || element->u || element->i || element->em) format[x][y - 1].reset = 1;
    }
}

void inherit(Element* parent, Element* child) {
    if (child->color == NONE) child->color = parent->color;
    if (child->em == 0) child->em = parent->em;
    if (child->i == 0) child->i = parent->i;
    if (child->u == 0) child->u = parent->u;
}

void calculate(Element* cur) {
    if (cur->type != DIV) return;
    int setw = cur->w != -1;
    int seth = cur->h != -1;
    if (!setw) cur->w = 0;
    if (!seth) cur->h = 0;
    for (int i = 0; i < cur->children_count; i++) {
        if (cur->children[i]->type == DIV) calculate(cur->children[i]);
        inherit(cur, cur->children[i]);
        if (cur->children[i]->type == IMG)
            cur->children[i]->h = ceil(strlen(cur->children[i]->src) / cur->children[i]->w);
        if (cur->direction == row) {
            if (!setw) cur->w = cur->w > cur->children[i]->w ? cur->w : cur->children[i]->w;
            if (!seth) cur->h += cur->children[i]->h;
        }
        else {
            if (!setw) cur->w += cur->children[i]->w;
            if (!seth) cur->h = cur->h > cur->children[i]->h ? cur->h : cur->children[i]->h;
        }
    }
}

void freeElement(Element* element) {
    for (int i = 0; i < element->children_count; i++) freeElement(element->children[i]);
    free(element);
}

int main(void) {
    Element* root = malloc(sizeof(Element));
    root->type = DIV;
    root->w = 50, root->h = 10;
    root->children_count = 0;
    analyse(root), calculate(root);
    memset(output, ' ', sizeof(output));
    render(root, 0, 0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            if (format[i][j].color == RED) printf(RED_COMMAND);
            if (format[i][j].color == BLUE) printf(BLUE_COMMAND);
            if (format[i][j].color == GREEN) printf(GREEN_COMMAND);
            if (format[i][j].em) printf(BOLD_COMMAND);
            if (format[i][j].i) printf(ITALIC_COMMAND);
            if (format[i][j].u) printf(UNDERLINE_COMMAND);
            printf("%c", output[i][j]);
            if (format[i][j].reset) printf(RESET_COMMAND);
        }
        if (i != 9) printf("\n");
    }
    freeElement(root);
    return 0;
}