#include "mainwindow.h"
#include "list_functions.h"
#include "./ui_mainwindow.h"
#include <QTextEdit>
#include <iostream>
#include <string>
#include <vector>
#include <QFileDialog>
#include <algorithm>
#include <QMessageBox>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hideAll();
}


MainWindow::~MainWindow()
{
    delete ui;
}

//functions for finding answers
int pow(int x, int y){
    if(y == 0){
        return 1;
    }
    int count = x;
    while(y > 1){
        count *= x;
        y -= 1;
    }
    return count;
}


void MainWindow::hideAll(){
    ui->back->setGeometry(100, -100, ui->back->width(), ui->back->height());
    ui->label->setGeometry(100, -100, ui->label->width(), ui->label->height());
    ui->textEdit->setGeometry(100, -1000, ui->textEdit->width(), ui->textEdit->height());
    ui->textEdit->clear();
    ui->enter_var->setGeometry(100, -1000, ui->enter_var->width(), ui->enter_var->height());
    ui->enter_var->clear();
    ui->textEdit_2->setGeometry(100, -1000, ui->textEdit_2->width(), ui->textEdit_2->height());
    ui->textEdit_2->clear();
    ui->textEdit_3->setGeometry(100, -1000, ui->textEdit_3->width(), ui->textEdit_3->height());
    ui->textEdit_3->clear();
    ui->textEdit_4->setGeometry(100, -1000, ui->textEdit_4->width(), ui->textEdit_4->height());
    ui->textEdit_4->clear();
    ui->textEdit_5->setGeometry(100, -1000, ui->textEdit_5->width(), ui->textEdit_5->height());
    ui->textEdit_5->clear();
    ui->textEdit_6->setGeometry(100, -1000, ui->textEdit_6->width(), ui->textEdit_6->height());
    ui->textEdit_6->clear();
    ui->textEdit_7->setGeometry(100, -1000, ui->textEdit_7->width(), ui->textEdit_7->height());
    ui->textEdit_7->clear();
    ui->textEdit_8->setGeometry(100, -1000, ui->textEdit_8->width(), ui->textEdit_8->height());
    ui->textEdit_8->clear();
    ui->textEdit_9->setGeometry(100, -1000, ui->textEdit_9->width(), ui->textEdit_9->height());
    ui->textEdit_9->clear();
    ui->textEdit_10->setGeometry(100, -1000, ui->textEdit_10->width(), ui->textEdit_10->height());
    ui->textEdit_10->clear();
    ui->textEdit_11->setGeometry(100, -1000, ui->textEdit_11->width(), ui->textEdit_11->height());
    ui->textEdit_11->clear();
    ui->textEdit_12->setGeometry(100, -1000, ui->textEdit_12->width(), ui->textEdit_12->height());
    ui->textEdit_12->clear();
    ui->textEdit_13->setGeometry(100, -1000, ui->textEdit_13->width(), ui->textEdit_13->height());
    ui->textEdit_13->clear();
    ui->enter_pol_num_ans_point->setGeometry(100, -1000, ui->enter_pol_num_ans_point->width(), ui->enter_pol_num_ans_point->height());
    ui->enter_pol_num_ans_point->clear();
    ui->textEdit_14->setGeometry(100, -1000, ui->textEdit_14->width(), ui->textEdit_14->height());
    ui->textEdit_14->clear();
    ui->save1->setGeometry(100, -1000, ui->save1->width(), ui->save1->height());
    ui->save1_2->setGeometry(100, -1000, ui->save1_2->width(), ui->save1_2->height());
    ui->save1_3->setGeometry(100, -1000, ui->save1_3->width(), ui->save1_3->height());
    ui->save1_4->setGeometry(100, -1000, ui->save1_4->width(), ui->save1_4->height());
    ui->save1_5->setGeometry(100, -1000, ui->save1_5->width(), ui->save1_5->height());
    ui->save1_6->setGeometry(100, -1000, ui->save1_6->width(), ui->save1_6->height());
    ui->save1_7->setGeometry(100, -1000, ui->save1_7->width(), ui->save1_7->height());
    ui->save1_8->setGeometry(100, -1000, ui->save1_8->width(), ui->save1_8->height());
    ui->save1_9->setGeometry(100, -1000, ui->save1_9->width(), ui->save1_9->height());
    ui->save1_10->setGeometry(100, -1000, ui->save1_10->width(), ui->save1_10->height());
    ui->label1->setGeometry(100, -1000, ui->label1->width(), ui->label1->height());
    ui->lable2_num->setGeometry(100, -1000, ui->lable2_num->width(), ui->lable2_num->height());
    ui->label2_var->setGeometry(100, -1000, ui->label2_var->width(), ui->label2_var->height());
    ui->lable3_num_1->setGeometry(100, -1000, ui->lable3_num_1->width(), ui->lable3_num_1->height());
    ui->lable3_num_2->setGeometry(100, -1000, ui->lable3_num_2->width(), ui->lable3_num_2->height());
    ui->lable3_num_3->setGeometry(100, -1000, ui->lable3_num_3->width(), ui->lable3_num_3->height());
    ui->lable3_num_4->setGeometry(100, -1000, ui->lable3_num_4->width(), ui->lable3_num_4->height());
    ui->lable3_num_5->setGeometry(100, -1000, ui->lable3_num_5->width(), ui->lable3_num_5->height());
    ui->lable3_num_6->setGeometry(100, -1000, ui->lable3_num_6->width(), ui->lable3_num_6->height());
    ui->lable3_num_7->setGeometry(100, -1000, ui->lable3_num_7->width(), ui->lable3_num_7->height());
    ui->lable3_num_8->setGeometry(100, -1000, ui->lable3_num_8->width(), ui->lable3_num_8->height());
    ui->lable3_num_9->setGeometry(100, -1000, ui->lable3_num_9->width(), ui->lable3_num_9->height());
    ui->lable3_num_10->setGeometry(100, -1000, ui->lable3_num_10->width(), ui->lable3_num_10->height());
    ui->lable3_num_11->setGeometry(100, -1000, ui->lable3_num_11->width(), ui->lable3_num_11->height());
    ui->lable3_num_12->setGeometry(100, -1000, ui->lable3_num_12->width(), ui->lable3_num_12->height());
    ui->spinBox->setGeometry(100, -1000, ui->spinBox->width(), ui->spinBox->height());
    ui->spinBox->clear();
    ui->pushButton->setGeometry(100, -1000, ui->pushButton->width(), ui->pushButton->height());
    ui->textEdit_15->setGeometry(100, -1000, ui->textEdit_15->width(), ui->textEdit_15->height());
    ui->textEdit_15->clear();
    ui->lable3_num_13->setGeometry(100, -1000, ui->lable3_num_13->width(), ui->lable3_num_13->height());
    ui->save1_11->setGeometry(100, -1000, ui->save1_11->width(), ui->save1_11->height());
}


void MainWindow::updateList(){
    ui->listWidget->clear();
    int i = 1;
    for(Node<linked_list<Elem>> * p = base.begin->next; p != base.end; p = p->next, ++i ){
        string ans = Out(p->elem);
        QString q_ans;
        string buf = to_string(i);
        for(int j = 0; j < buf.size(); ++j){
            q_ans += buf[j];
        }
        q_ans += '.';
        q_ans += ' ';
        for(int j = 0; j < ans.size(); ++j){
           q_ans += ans[j];
        }
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(q_ans);
        ui->listWidget->addItem(item);
    }
}

 //add elems
void MainWindow::on_add_clicked()
{
    hideAll();
    ui->label1->setGeometry(620, 220, ui->label1->width(), ui->label1->height());
    ui->textEdit->setGeometry(730, 220, ui->textEdit->width(), ui->textEdit->height());
    ui->save1->setGeometry(1120, 220, ui->save1->width(), ui->save1->height());
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
}


void MainWindow::on_save1_clicked()
{
    QString text = ui->textEdit->toPlainText();
    string polinom = text.toStdString();
    if(polinom.size() != 0) {
        int is_correct = check(polinom);
        if(is_correct) {
            updateList();
            hideAll();
        }
    }
}

//find answer in point
void MainWindow::on_ans_point_clicked()
{
    hideAll();
    ui->enter_pol_num_ans_point->setGeometry(660, 220, ui->enter_pol_num_ans_point->width(), ui->enter_pol_num_ans_point->height());
    ui->lable2_num->setGeometry(530, 220, ui->lable2_num->width(), ui->lable2_num->height());
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
    ui->save1_2->setGeometry(760, 220, ui->save1_2->width(), ui->save1_2->height());
}

//on save polinom
void MainWindow::on_save1_2_clicked()
{
    int count_pol = ui->enter_pol_num_ans_point->value();
    if((count_pol > base.size()) || (count_pol <= 0)) {
        NoPolinom(count_pol);
        return;
    }
    Node<linked_list<Elem>> *p = base.begin;
    for(int i = 0; i < count_pol; ++i){
        p = p->next;
    }
    if(p->elem.countVar() == 0){
        uncorrectPolinom(count_pol);
        return;
    }
    else {
        hideAll();
        now_ans_point = count_pol;
        ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
        ui->enter_var->setGeometry(640, 220, ui->enter_var->width(), ui->enter_var->height());
        ui->label2_var->setGeometry(540, 220, ui->label2_var->width(), ui->label2_var->height());
        ui->save1_9->setGeometry(850, 220, ui->save1_9->width(), ui->save1_9->height());
        ui->enter_var->setRowCount(p->elem.countVar());
        vector<int> var = p->elem.allVar();
        sort(var.begin(), var.end());
        curr = var;
        for(int i = 0; i < p->elem.countVar(); ++i) {
            QTableWidgetItem *item = new QTableWidgetItem;
            QString text;
            text = char('a' + var[i]);
            item->setText(text);
            item->setFlags(item->flags() &= ~(Qt::ItemIsSelectable | Qt::ItemIsEditable));
            ui->enter_var->setItem(i, 0, item);
        }
    }
}

//on save variables
void MainWindow::on_save1_9_clicked()
{
    int state = 0;
    vector<int> var(26);
    for(int i = 0; i < ui->enter_var->rowCount(); ++i){
        QTableWidgetItem *item = ui->enter_var->item(i, 1);
        if(item == 0){
            state = 1;
            noNum(i, 1);
            return;
        }
        else{
           QString x = item->text();
           QTableWidgetItem *item_left = ui->enter_var->item(i, 0);
           QString qtext = item_left->text();
           string text = qtext.toStdString();
           int a = text[0] - 'a';
           var[a] = stoi(item->text().toStdString());
        }
    }
    if(state == 0){
        Node<linked_list<Elem>> *p = base.begin;
        for(int i = 0; i < now_ans_point; ++i){
            p = p->next;
        }
        double ans = 0;
        for(Node<Elem> *q = p->elem.begin->next; q != p->elem.end; q = q->next) {
            double now = q->elem.ratio;
            for(int i = 0; i < 26; ++i){
                if(q->elem.variables[i] != 0){
                    now *= pow(var[i], q->elem.variables[i]);
                }
            }
            ans += now;
        }
        outAnsInPoint(ans);
        hideAll();
    }
}

//entering variables
void MainWindow::on_enter_var_cellChanged(int row, int column)
{
    QTableWidgetItem *item = ui->enter_var->item(row, column);
    if(column == 0){
        return;
    }
    if(item->text().size() == 0){
        return;
    }
    else{
        string text = item->text().toStdString();
        for(int i = 0; i < text.size(); ++i){
           if(text[i] < '0' || text[i] > '9') {
               item->setText("");
               onlyNum(row, column);
               return;
           }
        }
    }
}

//multiple
void MainWindow::on_multiple_clicked()
{
    hideAll();
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
    ui->lable3_num_1->setGeometry(530, 220, ui->lable3_num_1->width(), ui->lable3_num_1->height());
    ui->textEdit_2->setGeometry(680, 220, ui->textEdit_2->width(), ui->textEdit_2->height());
    ui->lable3_num_2->setGeometry(790, 220, ui->lable3_num_2->width(), ui->lable3_num_2->height());
    ui->textEdit_3->setGeometry(960, 220, ui->textEdit_3->width(), ui->textEdit_3->height());
    ui->save1_3->setGeometry(1070, 220, ui->save1_3->width(), ui->save1_3->height());
}


linked_list<Elem> Multiple(Node<linked_list<Elem>> *p, Node<linked_list<Elem>> *q){
    linked_list<Elem> new_polinom;
    for(Node<Elem> *i = p->elem.begin->next; i != p->elem.end; i = i->next) {
        for(Node<Elem> *j = q->elem.begin->next; j != q->elem.end; j = j->next) {
            Elem new_mono;
            new_mono.ratio = i->elem.ratio;
            new_mono.variables = i->elem.variables;
            new_mono.ratio *= j->elem.ratio;
            for(int k = 0; k < 26; ++k){
                new_mono.variables[k] += j->elem.variables[k];
            }
            new_polinom.insert_after(new_mono, new_polinom.end->prev);
        }
    }
    return new_polinom;
}

//on save polinom
void MainWindow::on_save1_3_clicked()
{
    int first = ui->textEdit_2->value();
    int second = ui->textEdit_3->value();
    if((first > base.size()) || (first <= 0)) {
        NoPolinom(first);
        return;
    }
    else if((second > base.size()) || (second <= 0)){
        NoPolinom(second);
        return;
    }
    else {
        Node<linked_list<Elem>> *p = base.begin;
        for(int i = 0; i < first; ++i){
            p = p->next;
        }
        Node<linked_list<Elem>> *q = base.begin;
        for(int i = 0; i < second; ++i){
            q = q->next;
        }
        linked_list<Elem> new_polinom = Multiple(p, q);
        Easyer(new_polinom);
        int res = outAnsMultiple(Out(new_polinom));
        if(res == 1) {
            base.insert_after(new_polinom, base.end->prev);
            updateList();
        }
        hideAll();
    }
}

//derivative
void MainWindow::on_deriv_clicked()
{
    hideAll();
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
    ui->textEdit_12->setGeometry(660, 220, ui->textEdit_12->width(), ui->textEdit_12->height());
    ui->lable3_num_11->setGeometry(530, 220, ui->lable3_num_11->width(), ui->lable3_num_11->height());
    ui->save1_6->setGeometry(760, 220, ui->save1_6->width(), ui->save1_6->height());
}

//on save polinom
void MainWindow::on_save1_6_clicked()
{
    int state = 0;
    int count_pol = ui->textEdit_12->value();
    if((count_pol > base.size()) || (count_pol <= 0)) {
        NoPolinom(count_pol);
        return;
    }
    cur_pol = count_pol;
    Node<linked_list<Elem>> *p = base.begin;
    for(int i = 0; i < count_pol; ++i){
        p = p->next;
    }
    if(p->elem.countVar() <= 1){
        state = 1;
    }
    if(state == 1){
        hideAll();
        ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
        ui->textEdit_13->setGeometry(660, 220, ui->textEdit_13->width(), ui->textEdit_13->height());
        ui->label->setGeometry(530, 220, ui->label->width(), ui->label->height());
        ui->save1_7->setGeometry(760, 220, ui->save1_7->width(), ui->save1_7->height());
        cur_state = 1;
    }
    else{
        hideAll();
        ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
        ui->textEdit_13->setGeometry(660, 220, ui->textEdit_13->width(), ui->textEdit_13->height());
        ui->label->setGeometry(530, 220, ui->label->width(), ui->label->height());
        ui->save1_8->setGeometry(760, 220, ui->save1_8->width(), ui->save1_8->height());
        ui->textEdit_14->setGeometry(660, 290, ui->textEdit_14->width(), ui->textEdit_14->height());
        ui->lable3_num_12->setGeometry(540, 290, ui->lable3_num_12->width(), ui->lable3_num_12->height());
        cur_state = 0;
    }

}

//on save derivation variable
void MainWindow::on_save1_7_clicked()
{
    int first = ui->textEdit_13->value();
    if(first < 1){
        outNotCorrectDeriv();
    }
    else{
        Node<linked_list<Elem>> *p = base.begin;
        for(int i = 0; i < cur_pol; ++i){
            p = p->next;
        }
        if(p->elem.countVar() == 0){
            linked_list<Elem> new_polinom;
            int res = outAnsDeriv(Out(new_polinom));
            if(res == 1) {
                base.insert_after(new_polinom, base.end->prev);
                updateList();
            }
            else {
                for(Node<Elem> *q = new_polinom.begin; q->next != new_polinom.end;){
                    delete(q->next);
                }
            }
        }
        else{
            linked_list<Elem> new_polinom;
            vector<int> need = p->elem.allVar();
            for(Node<Elem> *q = p->elem.begin->next; q != p->elem.end; q = q->next){
                Elem new_elem;
                new_elem.ratio = q->elem.ratio;
                new_elem.variables = q->elem.variables;
                for(int i = 0; i < 26; ++i) {
                    if(new_elem.variables[i] == 0 && i == need[0]) {
                        new_elem.ratio *= new_elem.variables[i];
                    }
                    else if(i == need[0]) {
                        new_elem.ratio *= new_elem.variables[i];
                        --new_elem.variables[i];
                    }
                }
                new_polinom.insert_after(new_elem, new_polinom.end->prev);
            }
            --first;
            Easyer(new_polinom);
            for(int i = 0; i < first; ++i){
                for(Node<Elem> *q = new_polinom.begin->next; q != new_polinom.end; q = q->next){
                    for(int i = 0; i < 26; ++i){
                        if(q->elem.variables[i] == 0 && i == need[0]) {
                            q->elem.ratio *= q->elem.variables[i];
                        }
                        else if(i == need[0]){
                            q->elem.ratio *= q->elem.variables[i];
                            --q->elem.variables[i];
                        }
                    }
                }
                Easyer(new_polinom);
            }
            int res = outAnsDeriv(Out(new_polinom));
            if(res == 1) {
                base.insert_after(new_polinom, base.end->prev);
                updateList();
            }
            hideAll();
        }

    }
}

//on save order
void MainWindow::on_save1_8_clicked()
{
    int first = ui->textEdit_13->value(); //порядок производной
    QString second = ui->textEdit_14->toPlainText(); //переменная, относительно которой берем производную
    string text = second.toStdString();
    if(text == "") {
        outNoText();
        return;
    }
    Node<linked_list<Elem>> *p = base.begin;
    for(int i = 0; i < cur_pol; ++i){
        p = p->next;
    }

    linked_list<Elem> new_polinom;

    for(Node<Elem> *q = p->elem.begin->next; q != p->elem.end; q = q->next){
        Elem new_elem;
        new_elem.ratio = q->elem.ratio;
        new_elem.variables = q->elem.variables;

        for(int i = 0; i < 26; ++i){
            if(new_elem.variables[i] == 0 && i == text[0] - 'a') {
                new_elem.ratio *= new_elem.variables[i];
            }
            else if(i == text[0] - 'a'){
                new_elem.ratio *= new_elem.variables[i];
                --new_elem.variables[i];
            }
        }

        new_polinom.insert_after(new_elem, new_polinom.end->prev);

    }

    --first;
    Easyer(new_polinom);

    for(int i = 0; i < first; ++i){

        for(Node<Elem> *q = new_polinom.begin->next; q != new_polinom.end; q = q->next){

            for(int i = 0; i < 26; ++i){
                if(q->elem.variables[i] == 0 && i == text[0] - 'a') {
                    q->elem.ratio *= q->elem.variables[i];
                }
                else if(i == text[0] - 'a'){
                    q->elem.ratio *= q->elem.variables[i];
                    --q->elem.variables[i];
                }
            }

        }

        Easyer(new_polinom);

    }

    int res = outAnsDeriv(Out(new_polinom));
    if(res == 1) {
        base.insert_after(new_polinom, base.end->prev);
        updateList();
    }
    else{
        for(Node<Elem> *q = new_polinom.begin; q->next != new_polinom.end;){
            delete(q->next);
        }
    }
    hideAll();
}

//entering variable
void MainWindow::on_textEdit_14_textChanged()
{
    if(ui->textEdit_14->toPlainText().size() == 0){
        return;
    }
    else if(ui->textEdit_14->toPlainText().size() == 1){
        Node<linked_list<Elem>> *p = base.begin;
        for(int i = 0; i < cur_pol; ++i){
            p = p->next;
        }
        vector<int> var = p->elem.allVar();
        for(int i = 0; i < var.size(); ++i){
            if(var[i] == ui->textEdit_14->toPlainText().toStdString()[0] - 'a'){
                return;
            }
        }
        ui->textEdit_14->setText("");
        onlyAlfabet();
        return;
    }
    else{
        ui->textEdit_14->setText("");
        onlyAlfabet();
        return;
    }
}

//comporation
void MainWindow::on_compare_clicked()
{
    hideAll();
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
    ui->lable3_num_3->setGeometry(530, 220, ui->lable3_num_1->width(), ui->lable3_num_1->height());
    ui->textEdit_4->setGeometry(680, 220, ui->textEdit_2->width(), ui->textEdit_2->height());
    ui->lable3_num_4->setGeometry(790, 220, ui->lable3_num_2->width(), ui->lable3_num_2->height());
    ui->textEdit_5->setGeometry(960, 220, ui->textEdit_3->width(), ui->textEdit_3->height());
    ui->save1_4->setGeometry(1070, 220, ui->save1_3->width(), ui->save1_3->height());
}

//on save polinoms
void MainWindow::on_save1_4_clicked()
{
    int is_correct = 1;
    int first = ui->textEdit_4->value();
    int second = ui->textEdit_5->value();
    if((first > base.size()) || (first <= 0)) {
        NoPolinom(first);
        return;
    }
    else if((second > base.size()) || (second <= 0)){
        NoPolinom(second);
        return;
    }
    else {
        Node<linked_list<Elem>> *p = base.begin;
        for(int i = 0; i < first; ++i){
            p = p->next;
        }
        Node<linked_list<Elem>> *q = base.begin;
        for(int i = 0; i < second; ++i){
            q = q->next;
        }
        Node<Elem> *j = q->elem.begin->next;
        Node<Elem> *i = p->elem.begin->next;
        for(; i != p->elem.end && j != q->elem.end; i = i->next, j = j->next) {
            if((i->elem.ratio == j->elem.ratio) && (i->elem.variables == j->elem.variables)) {

            }
            else {
                is_correct = 0;
            }
        }
        if(i == p->elem.end && j == q->elem.end && is_correct == 1){
            QMessageBox msgBox;
            msgBox.setText("Polinomials are similar");
            msgBox.exec();
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Polinomials are not similar");
            msgBox.exec();
        }
        hideAll();
    }
}

//summ
void MainWindow::on_summ_clicked()
{
    hideAll();
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
    ui->lable3_num_4->setGeometry(530, 220, ui->lable3_num_1->width(), ui->lable3_num_1->height());
    ui->textEdit_6->setGeometry(680, 220, ui->textEdit_2->width(), ui->textEdit_2->height());
    ui->lable3_num_5->setGeometry(790, 220, ui->lable3_num_2->width(), ui->lable3_num_2->height());
    ui->textEdit_7->setGeometry(960, 220, ui->textEdit_3->width(), ui->textEdit_3->height());
    ui->save1_5->setGeometry(1070, 220, ui->save1_3->width(), ui->save1_3->height());
}


linked_list<Elem> Summ(Node<linked_list<Elem>> *p, Node<linked_list<Elem>> *q){
    linked_list<Elem> new_polinom;
    Node<Elem> *j = q->elem.begin->next;
    Node<Elem> *i = p->elem.begin->next;
    for(; i != p->elem.end ; i = i->next) {
        new_polinom.insert_after(i->elem, new_polinom.end->prev);
    }
    for(; j != q->elem.end ; j = j->next) {
        new_polinom.insert_after(j->elem, new_polinom.end->prev);
    }
    return new_polinom;
}


linked_list<Elem> notSumm(Node<linked_list<Elem>> *p, Node<linked_list<Elem>> *q){
    Node<linked_list<Elem>> *minus = new Node<linked_list<Elem>>;
    Elem i;
    i.ratio = -1;
    minus->elem.insert_after(i, minus->elem.begin);
    Node<linked_list<Elem>> *c = new Node<linked_list<Elem>>;
    c->elem = Multiple(q, minus);
    delete(minus);
    Easyer(c->elem);
    linked_list<Elem> ans = Summ(p, c);
    delete(c);
    Easyer(ans);
    return ans;
}

//on save polinoms
void MainWindow::on_save1_5_clicked()
{
    int first = ui->textEdit_6->value();
    int second = ui->textEdit_7->value();
    if((first > base.size()) || (first <= 0)) {
        NoPolinom(first);
        return;
    }
    else if((second > base.size()) || (second <= 0)){
        NoPolinom(second);
        return;
    }
    else {
        Node<linked_list<Elem>> *p = base.begin;
        for(int i = 0; i < first; ++i){
            p = p->next;
        }
        Node<linked_list<Elem>> *q = base.begin;
        for(int i = 0; i < second; ++i){
            q = q->next;
        }
        linked_list<Elem> new_polinom = Summ(p, q);
        Easyer(new_polinom);
        int res = outSumm(Out(new_polinom));
        if(res == 1) {
            base.insert_after(new_polinom, base.end->prev);
            updateList();
        }
        hideAll();
    }
}

//division
void MainWindow::on_div_clicked()
{
    hideAll();
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
    ui->lable3_num_7->setGeometry(540, 220, ui->lable3_num_7->width(), ui->lable3_num_7->height());
    ui->textEdit_8->setGeometry(690, 220, ui->textEdit_8->width(), ui->textEdit_8->height());
    ui->lable3_num_8->setGeometry(800, 220, ui->lable3_num_8->width(), ui->lable3_num_8->height());
    ui->textEdit_9->setGeometry(970, 220, ui->textEdit_9->width(), ui->textEdit_9->height());
    ui->save1_10->setGeometry(1070, 220, ui->save1_10->width(), ui->save1_10->height());
}

//on save polinoms
void MainWindow::on_save1_10_clicked()
{
    int first = ui->textEdit_8->value();
    int second = ui->textEdit_9->value();
    if((first > base.size()) || (first <= 0)) {
        NoPolinom(first);
        return;
    }
    else if((second > base.size()) || (second <= 0)){
        NoPolinom(second);
        return;
    }
    else {
        Node<linked_list<Elem>> *p = base.begin;
        for(int i = 0; i < first; ++i){
            p = p->next;
        }
        if(p->elem.countVar() > 1){
            uncorrectDivide(first);
            return;
        }
        Node<linked_list<Elem>> *q = base.begin;
        for(int i = 0; i < second; ++i){
            q = q->next;
        }
        if(q->elem.countVar() > 1){
            uncorrectDivide(second);
            return;
        }
        if(q->elem.allVar() != p->elem.allVar() && !(p->elem.countVar() == 0 || q->elem.countVar() == 0)){
            notSimilarDivide();
            return;
        }
        Node<linked_list<Elem>> *new_polinom = new Node<linked_list<Elem>>;
        linked_list<Elem> now;
        if(q->elem.countVar() == 0 && q->elem.begin->next == q->elem.end){
            cantDivideZero();
            delete(new_polinom);
            return;
        }
        else if (p->elem.countVar() == 0 && p->elem.begin->next == p->elem.end) {
            int res = outAnsDivide(Out(new_polinom->elem), Out(now));
            if(res == 1){
                base.insert_after(new_polinom->elem, base.end->prev);
                updateList();
            }
            else if (res == 2){
                base.insert_after(now, base.end->prev);
                updateList();
            }
            else if(res == 3){
                base.insert_after(new_polinom->elem, base.end->prev);
                base.insert_after(now, base.end->prev);
                updateList();
            }
            else{
                int res = outAnsDivide(Out(new_polinom->elem), Out(q->elem));
                if(res == 1){
                    base.insert_after(new_polinom->elem, base.end->prev);
                    updateList();
                }
                else if (res == 2){
                    base.insert_after(q->elem, base.end->prev);
                    updateList();
                }
                else if(res == 3){
                    base.insert_after(new_polinom->elem, base.end->prev);
                    base.insert_after(q->elem, base.end->prev);
                    updateList();
                }
            }
        }
        else if(q->elem.countVar() == 0) {
            for(Node<Elem> * n = p->elem.begin->next; n != p->elem.end; n = n->next){
                Elem m;
                m.ratio = n->elem.ratio;
                m.variables = n->elem.variables;
                m.ratio /= q->elem.begin->next->elem.ratio;
                now.insert_after(m, now.end->prev);
            }
            int res = outAnsDivide(Out(now), Out(new_polinom->elem));
            if(res == 1){
                base.insert_after(now, base.end->prev);
                updateList();
            }
            else if (res == 2){
                base.insert_after(new_polinom->elem, base.end->prev);
                updateList();
            }
            else if(res == 3){
                base.insert_after(now, base.end->prev);
                base.insert_after(new_polinom->elem, base.end->prev);
                updateList();
            }
        }
        else {
            for(Node<Elem> * n = p->elem.begin->next; n != p->elem.end; n = n->next){
                now.insert_after(n->elem, now.end->prev);
            }
            for(Node<Elem> *n = now.begin->next; n != now.end;n = n->next){
                if(n->prev != now.begin){

                }
            }
            vector<int> var = now.allVar();
            while((findHigher(now) >= findHigher(q->elem)) && (findHigher(now) != 0 || findHigher(q->elem) != 0)){
                Elem buf;
                buf.ratio = double(findHigherKof(now))/double(findHigherKof(q->elem));
                buf.variables[var[0]] = findHigher(now) - findHigher(q->elem);
                new_polinom->elem.insert_after(buf, new_polinom->elem.end->prev);
                Node<linked_list<Elem>> *c = new Node<linked_list<Elem>>;
                c->elem = Multiple(q, new_polinom);
                Easyer(c->elem);
                for(Node<Elem> *n = now.begin->next; n != now.end;n = n->next){
                    if(n->prev != now.begin){
                        delete(n->prev);
                        n->prev = now.begin;
                        now.begin->next = n;
                    }
                }
                now = notSumm(p, c);
                delete(c);
            }
            Easyer(new_polinom->elem);
            Easyer(now);
            int res = outAnsDivide(Out(new_polinom->elem), Out(now));
            if(res == 1){
                base.insert_after(new_polinom->elem, base.end->prev);
                updateList();
            }
            else if (res == 2){
                base.insert_after(now, base.end->prev);
                updateList();
            }
            else if(res == 3){
                base.insert_after(new_polinom->elem, base.end->prev);
                base.insert_after(now, base.end->prev);
                updateList();
            }
        }
        delete(new_polinom);
    }
}

//all answers
void MainWindow::on_all_answers_clicked()
{
    hideAll();
    ui->textEdit_15->setGeometry(660, 220, ui->textEdit_15->width(), ui->textEdit_15->height());
    ui->lable3_num_13->setGeometry(530, 220, ui->lable3_num_13->width(), ui->lable3_num_13->height());
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
    ui->save1_11->setGeometry(760, 220, ui->save1_11->width(), ui->save1_11->height());
}


int point(int count, vector<int> var){
    Node<linked_list<Elem>> *p = base.begin;
    for(int i = 0; i < count; ++i){
        p = p->next;
    }
    double ans = 0;
    for(Node<Elem> *q = p->elem.begin->next; q != p->elem.end; q = q->next) {
        double now = q->elem.ratio;
        for(int i = 0; i < 26; ++i){
            if(q->elem.variables[i] != 0){
                now *= pow(var[i], q->elem.variables[i]);
            }
        }
        ans += now;
    }
    return ans;
}


void MainWindow::on_save1_11_clicked()
{
    int count_pol = ui->textEdit_15->value();
    if((count_pol > base.size()) || (count_pol <= 0)) {
        NoPolinom(count_pol);
        return;
    }
    Node<linked_list<Elem>> *p = base.begin;
    for(int i = 0; i < count_pol; ++i){
        p = p->next;
    }
    if(p->elem.countVar() == 0){
        uncorrectPolinom(count_pol);
        return;
    }
    else if(p->elem.countVar() > 1){
        uncorrectFinding();
        return;
    }
    else {
        hideAll();
        Node<Elem> *q = p->elem.begin->next;
        int max = 0;
        for(; q != p->elem.end; q = q->next){
            double y = q->elem.ratio;
            int x = y;
            int count = 0;
            while(x != y){
                y *= 10;
                x = y;
                ++count;
            }
            if(max < count){
                max = count;
            }
        }
        Node<linked_list<Elem>> *ten = new Node<linked_list<Elem>>;
        Elem ten_elem;
        ten_elem.ratio = 10;
        ten->elem.insert_after(ten_elem, ten->elem.end->prev);
        Node<linked_list<Elem>> *copy = new Node<linked_list<Elem>>;
        for(Node<Elem> *r = p->elem.begin->next; r != p->elem.end; r = r->next){
            copy->elem.insert_after(r->elem, copy->elem.end->prev);
        }
        for(int i = 0; i < max; ++i){
            Multiple(copy, ten);
        }
        double min = FindMin(copy->elem);
        vector<int> ratio(26);
        vector<int> var;
        var = p->elem.allVar();
        vector<int> ans;
        for(int i = -abs(min); i <= abs(min); ++i) {
            ratio[var[0]] = i;
            double res = point(count_pol, ratio);
            if(res == 0){
                ans.push_back(i);
            }
        }
        delete(ten);
        delete(copy);
        outAllAswers(ans);
    }
}

//back
void MainWindow::on_back_clicked()
{
    hideAll();
}

//load
void MainWindow::on_load_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    //dialog.setNameFilter(tr("Images (*.txt)"));
    dialog.setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    if(fileNames.size() == 0) return;
    string load = fileNames[0].toStdString();
    string entered;
    ifstream fin(load);
    while(fin>>entered){
        if(entered.size() != 0) {
            int is_correct = check_copy(entered);
            if(is_correct) {
                updateList();
                hideAll();
            }
        }
    }
}

//save
void MainWindow::on_save_clicked()
{
    QString fileNames = QFileDialog::getSaveFileName(this, "Save");
    if (fileNames == "") return;
    if(fileNames.size() > 0) {
        string load = fileNames.toStdString();
        ofstream fout(load);
        for(Node<linked_list<Elem>> *p = base.begin->next; p != base.end; p = p->next){
            string out = Out(p->elem);
            fout<<out<<'\n';
        }
    }
}

//delete elem
void MainWindow::on_delete_2_clicked()
{
    hideAll();
    ui->back->setGeometry(1080, 130, ui->back->width(), ui->back->height());
    ui->spinBox->setGeometry(550, 660, ui->spinBox->width(), ui->spinBox->height());
    ui->pushButton->setGeometry(680, 660, ui->pushButton->width(), ui->pushButton->height());
}

//on save polinom
void MainWindow::on_pushButton_clicked()
{
    int count_pol = ui->spinBox->value();
    if((count_pol > base.size()) || (count_pol <= 0)) {
        NoPolinom(count_pol);
        return;
    }
    Node<linked_list<Elem>> *p = base.begin;
    for(int i = 0; i < count_pol; ++i){
        p = p->next;
    }
    base.collapse(p);
    hideAll();
    updateList();
}
