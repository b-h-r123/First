
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ==================== 自定义结构体区域 ====================
// 你可以修改这个结构体来适应你的需求
typedef struct {
    int id;                 // 学号/ID
    char name[50];          // 姓名
    int age;                // 年龄
    float score;            // 分数
    char gender[1];        // 性别
} Student;

// 你也可以定义其他结构体，例如：
// typedef struct {
//     int product_id;
//     char product_name[100];
//     float price;
//     int stock;
// } Product;

// ==================== 全局变量和常量 ====================
#define MAX_SIZE 1000       // 最大记录数
#define FILENAME "data.dat" // 数据文件名

Student records[MAX_SIZE];  // 存储所有记录
int record_count = 0;       // 当前记录数

// ==================== 函数声明 ====================
void initSystem();          // 初始化系统
void loadFromFile();        // 从文件加载数据
void saveToFile();          // 保存数据到文件

void showMenu();            // 显示菜单
void addRecord();           // 增加记录
void deleteRecord();        // 删除记录
void modifyRecord();        // 修改记录
void searchRecord();        // 查询记录
void displayAllRecords();   // 显示所有记录

int findRecordById(int id); // 根据ID查找记录索引
void inputRecord(Student* record); // 输入记录信息
void displayRecord(Student record); // 显示单个记录

// ==================== 主函数 ====================
int main() {
    initSystem();

    int choice;

    while (1) {
        showMenu();
        printf("请选择操作 (0-6): ");
        scanf("%d", &choice);

        // 清空输入缓冲区
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            deleteRecord();
            break;
        case 3:
            modifyRecord();
            break;
        case 4:
            searchRecord();
            break;
        case 5:
            displayAllRecords();
            break;
        case 6:
            saveToFile();
            printf("数据已保存，程序退出！\n");
            return 0;
        case 0:
            printf("程序退出，未保存更改！\n");
            return 0;
        default:
            printf("无效的选择，请重新输入！\n");
        }

        printf("\n按Enter键继续...");
        getchar();
    }

    return 0;
}

// ==================== 函数实现 ====================

// 初始化系统
void initSystem() {
    printf("========== 学生管理系统 ==========\n");
    printf("系统初始化中...\n");
    loadFromFile();
    printf("当前共有 %d 条记录\n", record_count);
}

// 从文件加载数据
void loadFromFile() {
    FILE* file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("未找到数据文件，将创建新文件\n");
        return;
    }

    fread(&record_count, sizeof(int), 1, file);
    fread(records, sizeof(Student), record_count, file);

    fclose(file);
    printf("数据加载成功！\n");
}

// 保存数据到文件
void saveToFile() {
    FILE* file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("无法创建数据文件！\n");
        return;
    }

    fwrite(&record_count, sizeof(int), 1, file);
    fwrite(records, sizeof(Student), record_count, file);

    fclose(file);
    printf("数据保存成功！\n");
}

// 显示菜单
void showMenu() {
    printf("\n========== 菜单 ==========\n");
    printf("1. 增加学生记录\n");
    printf("2. 删除学生记录\n");
    printf("3. 修改学生记录\n");
    printf("4. 查询学生记录\n");
    printf("5. 显示所有记录\n");
    printf("6. 保存并退出\n");
    printf("0. 退出（不保存）\n");
    printf("==========================\n");
}

// 输入记录信息
void inputRecord(Student* record) {
    printf("请输入学号: ");
    scanf("%d", &record->id);

    printf("请输入姓名: ");
    scanf("%s", record->name);

    printf("请输入年龄: ");
    scanf("%d", &record->age);

    printf("请输入性别: ");
    scanf("%s", record->gender);

    printf("请输入分数: ");
    scanf("%f", &record->score);
}

// 显示单个记录
void displayRecord(Student record) {
    printf("┌────────────────────────────────────────────┐\n");
    printf("│ 学号: %-8d    姓名: %-20s │\n", record.id, record.name);
    printf("│ 年龄: %-8d    性别: %-20s │\n", record.age, record.gender);
    printf("│ 分数: %-8.2f                             │\n", record.score);
    printf("└────────────────────────────────────────────┘\n");
}

// 增加记录
void addRecord() {
    if (record_count >= MAX_SIZE) {
        printf("记录已满，无法添加！\n");
        return;
    }

    Student new_record;
    printf("\n=== 添加新记录 ===\n");

    // 检查ID是否重复
    int new_id;
    printf("请输入学号: ");
    scanf("%d", &new_id);

    if (findRecordById(new_id) != -1) {
        printf("学号 %d 已存在，添加失败！\n", new_id);
        return;
    }

    new_record.id = new_id;

    printf("请输入姓名: ");
    scanf("%s", new_record.name);

    printf("请输入年龄: ");
    scanf("%d", &new_record.age);

    printf("请输入性别: ");
    scanf("%s", new_record.gender);

    printf("请输入分数: ");
    scanf("%f", &new_record.score);

    records[record_count] = new_record;
    record_count++;

    printf("\n记录添加成功！\n");
    displayRecord(new_record);
}

// 删除记录
void deleteRecord() {
    if (record_count == 0) {
        printf("没有记录可删除！\n");
        return;
    }

    int id;
    printf("\n=== 删除记录 ===\n");
    printf("请输入要删除的学号: ");
    scanf("%d", &id);

    int index = findRecordById(id);
    if (index == -1) {
        printf("未找到学号为 %d 的记录！\n", id);
        return;
    }

    printf("找到以下记录：\n");
    displayRecord(records[index]);

    printf("确认删除？(y/n): ");
    char confirm;
    scanf(" %c", &confirm);
    int i=0; 

    if (confirm == 'y' || confirm == 'Y') {
        // 将后面的记录前移
        for (i = index; i < record_count - 1; i++) {
            records[i] = records[i + 1];
        }
        record_count--;
        printf("记录删除成功！\n");
    }
    else {
        printf("取消删除操作\n");
    }
}

// 修改记录
void modifyRecord() {
    if (record_count == 0) {
        printf("没有记录可修改！\n");
        return;
    }

    int id;
    printf("\n=== 修改记录 ===\n");
    printf("请输入要修改的学号: ");
    scanf("%d", &id);

    int index = findRecordById(id);
    if (index == -1) {
        printf("未找到学号为 %d 的记录！\n", id);
        return;
    }

    printf("找到原记录：\n");
    displayRecord(records[index]);

    printf("\n请输入新的信息：\n");

    printf("请输入新姓名 (原: %s): ", records[index].name);
    char new_name[50];
    scanf("%s", new_name);
    if (strlen(new_name) > 0) {
        strcpy(records[index].name, new_name);
    }

    printf("请输入新年龄 (原: %d): ", records[index].age);
    int new_age;
    if (scanf("%d", &new_age) == 1) {
        records[index].age = new_age;
    }

    printf("请输入新性别 (原: %s): ", records[index].gender);
    char new_gender[10];
    scanf("%s", new_gender);
    if (strlen(new_gender) > 0) {
        strcpy(records[index].gender, new_gender);
    }

    printf("请输入新分数 (原: %.2f): ", records[index].score);
    float new_score;
    if (scanf("%f", &new_score) == 1) {
        records[index].score = new_score;
    }

    printf("\n修改后的记录：\n");
    displayRecord(records[index]);
}

// 查询记录
void searchRecord() {
    if (record_count == 0) {
        printf("没有记录可查询！\n");
        return;
    }

    printf("\n=== 查询记录 ===\n");
    printf("1. 按学号查询\n");
    printf("2. 按姓名查询\n");
    printf("3. 按分数范围查询\n");
    printf("请选择查询方式: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
        int id;
        printf("请输入学号: ");
        scanf("%d", &id);

        int index = findRecordById(id);
        if (index == -1) {
            printf("未找到学号为 %d 的记录\n", id);
        }
        else {
            printf("\n查询结果：\n");
            displayRecord(records[index]);
        }
        break;
    }
    case 2: {
        char name[50];
        printf("请输入姓名: ");
        scanf("%s", name);
        int i = 0

        bool found = false;
        for (i = 0; i < record_count; i++) {
            if (strstr(records[i].name, name) != NULL) {
                if (!found) {
                    printf("\n查询结果：\n");
                    found = true;
                }
                displayRecord(records[i]);
            }
        }

        if (!found) {
            printf("未找到姓名为 %s 的记录\n", name);
        }
        break;
    }
    case 3: {
        float min_score, max_score;
        printf("请输入最低分数: ");
        scanf("%f", &min_score);
        printf("请输入最高分数: ");
        scanf("%f", &max_score);

        bool found = false;
        for (int i = 0; i < record_count; i++) {
            if (records[i].score >= min_score && records[i].score <= max_score) {
                if (!found) {
                    printf("\n查询结果 (分数范围 %.2f-%.2f)：\n", min_score, max_score);
                    found = true;
                }
                displayRecord(records[i]);
            }
        }

        if (!found) {
            printf("未找到分数在 %.2f-%.2f 之间的记录\n", min_score, max_score);
        }
        break;
    }
    default:
        printf("无效的选择\n");
    }
}

// 显示所有记录
void displayAllRecords() {
    if (record_count == 0) {
        printf("暂无记录！\n");
        return;
    }

    printf("\n=== 所有记录 (共%d条) ===\n", record_count);

    // 显示表头
    printf("┌──────┬────────────┬──────┬────────┬────────┐\n");
    printf("│ 学号 │    姓名    │ 年龄 │  性别  │  分数  │\n");
    printf("├──────┼────────────┼──────┼────────┼────────┤\n");

    // 显示每条记录
    for (int i = 0; i < record_count; i++) {
        printf("│ %4d │ %-10s │ %4d │ %-6s │ %6.2f │\n",
            records[i].id,
            records[i].name,
            records[i].age,
            records[i].gender,
            records[i].score);
    }

    printf("└──────┴────────────┴──────┴────────┴────────┘\n");

    // 统计信息
    if (record_count > 0) {
        float total_score = 0;
        float max_score = records[0].score;
        float min_score = records[0].score;

        for (int i = 0; i < record_count; i++) {
            total_score += records[i].score;
            if (records[i].score > max_score) max_score = records[i].score;
            if (records[i].score < min_score) min_score = records[i].score;
        }

        printf("\n统计信息：\n");
        printf("平均分: %.2f  最高分: %.2f  最低分: %.2f\n",
            total_score / record_count, max_score, min_score);
    }
}

// 根据ID查找记录索引
int findRecordById(int id) {
    for (int i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1;
}
