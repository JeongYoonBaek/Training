﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BookManager
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            if (DataManager.books.Count > 0) 
                bookBindingSource.DataSource = DataManager.books;   
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool existBook = false; // 책이 있는 지 없는 지 여부 (변수로)
            foreach(var item in DataManager.books)
            {
                // 참고로 문자열 비교시 equlas 대신 == 써도 됨
                // java는 버전에 따라서 equals만 써야 할 수도 있고
                // ==도 되는 경우도 있음
                if(item.isbn == textBox1.Text)  // 책이 100권이 있는데 isbn 값이 1234가 있는지 확인함 
                {
                    existBook = true;   // 책이 있으면 책을 추가하면 안됨 (겹치면 안됨) isbn은 일종의 PK
                    break;
                }
                if(existBook)
                    MessageBox.Show("이미 해당 책 존재합니다.");
                else
                {
                    Book book = new Book(); 
                    book.isbn = textBox1.Text;
                    book.name = textBox2.Text;
                    book.publisher = textBox3.Text;
                    int.TryParse(textBox4.Text, out int page);
                    book.page = page;
                    if (page <= 0)
                    {
                        throw new Exception("Page가 이상해요!"); // try catch 코드 배웠으니 한번 적용해봤음.
                        return;
                    }
                    DataManager.books.Add(book);
                    bookBindingSource.DataSource = DataManager.books;
                    DataManager.Save();
                }
            }       
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView2_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            Book b = dataGridView2.CurrentRow.DataBoundItem as Book;
            textBox1.Text = b.isbn;
            textBox2.Text = b.name;
            textBox3.Text = b.publisher;
            textBox4.Text = b.page.ToString();

        }
    }
}
