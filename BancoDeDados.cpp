#include "Datas.h"

using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bool ext = false;                                      //  ---- controle do main
    int nArray = 0, fie1[20][30], floatPoint = 0;          //  ---- variáveis auxiliares
    int num, baseQuant, tableQuant, fieldQuant, quantComp; //  ---- Contadores de elementos
    string fie2[20], command, database, table, atualDb1;   //  ---- armazenadores de elementos
    stringstream conc1, conc2, conc3, conc4[20]; 		   //  ---- concatenadores dos elementos
	string registers;									   //
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Função pra verificar se contem caracteres
bool cont(string first, string second)
{
     int pos = 0;
     pos = first.find(second);
     
     if(pos == -1)
         return false;
     else
         return true;    
          
}

//Conversor de char* para std::string
string FcharTstring(char* val)
{ 
        std::stringstream datas;
        for(int i=0; i < strlen(val)-1; i++){
              datas << val[i];
        }
        return datas.str();
}

//Verificar se um caracter é numérico
bool isNumeric(char al){
	
	if(al == '.')
		floatPoint++;
	
	if(al == '0')
		return true;
	else if(al == '1')
		return true; 
	else if(al == '2')
		return true;
	else if(al == '3')
		return true;
	else if(al == '4')
		return true;
	else if(al == '5')
		return true;
	else if(al == '6')
		return true;
	else if(al == '7')
		return true;
	else if(al == '8')
		return true;
	else if(al == '9')
		return true;
	else if(al == '.' && floatPoint < 2)
		return true;
	else
		return false;
}

DataBase gerar_Reg(int dataSize, int tableSize, int b1[], int t1[])
{
     DataBase registers;
     int i = 0;
     for(i = 0; i < 20; i++){
           if(i < dataSize)
               registers.database[i] = b1[i];
           else
               registers.database[i] = -1;
             
     }
     
     for(i = 0; i < 20; i++){
           if(i < tableSize)
                registers.table[i] = t1[i];
           else
                registers.table[i] = -1;
                 
     }
    
     for(int i = 0; i < 20; i++){
           for(int j = 0; j < 30; j++){
                 if(i < nArray)
                      if(j < fie2[i].length())
                           registers.field[i][j] = fie1[i][j];
                      else
                           registers.field[i][j] = -1;
                 else
                      registers.field[i][j] = -1;
           }
     }
     nArray = 0;
             
     return registers;                    
}

void exibir_Registros(DataBase data, string comm, int val1, int val2)
{
      char search[20];
      char search2[20];
      char search3[20];
      if(comm == "ALL_DATABASE"){
          
          for(int i = 0; i < 20; i++)
                  search[i] = (data.database[i] != -1) ? data.database[i] : -1;
          
          conc2 << ">" << search;
          if(!cont(conc1.str(), conc2.str())){       
               conc1 << ">" << search << "\n";
               quantComp++;
          }
               
          conc2.str("");
          if(val1 == (val2-1)){
               cout << "\n----------------------------------------------------\n";
               cout << conc1.str() << endl;
               cout << "----------------------------------------------------\n";
               cout << "BASES ENCONTRADAS : " << quantComp << endl;
               quantComp = 0;
               conc1.str("");
          }
          for(int i = 0; i < 20; i++)
                  search[i] = -1;
                  
      }else{
          if(comm == "ALL_TABLE_NO_BASE"){
              
              for(int i = 0; i < 20; i++)
                      search[i] = (data.table[i] != -1) ? data.table[i] : 0;
              
              conc2 << ">" << search;
              if(!cont(conc1.str(), conc2.str())){       
                   conc1 << ">" << search << "\n";
                   quantComp++;
              }
                   
              conc2.str("");
              if(val1 == (val2-1)){
                   cout << "\n----------------------------------------------------\n";
                   cout << conc1.str() << endl;
                   cout << "----------------------------------------------------\n";
                   cout << "TABELAS ENCONTRADAS : " << quantComp << endl;
                   quantComp = 0;
                   conc1.str("");
              } 
              for(int i = 0; i < 20; i++)
                  search[i] = -1;
          }else{
              if(cont(comm, "ALL_TABLE_IN_BASE")){
                  string myDb = comm.substr(comm.find(":")+1, comm.length());
                  string atualDb;
                  for(int i = 0; i < 20; i++)
                          search[i] = (data.database[i] != -1) ? data.database[i] : 0;
                  
                  for(int i = 0; i < 20; i++)
                          search2[i] = (data.table[i] != -1) ? data.table[i] : 0;
                          
                  atualDb = search;
                  if(atualDb == myDb){      
                       conc1 << "\t>" << search2 << "\n";
                       atualDb1 = atualDb;
                       quantComp++;
                  }
                       
                  if(val1 == (val2-1)){
                      if(quantComp > 0){
                        cout << "\n----------------------------------------------------\n";
                        cout << ">" << atualDb1 << endl;
                        cout << conc1.str() << endl;
                        cout << "----------------------------------------------------\n";
                        cout << "TABELAS ENCONTRADAS EM '" << atualDb1 << "' : " << quantComp << endl;
                        conc1.str("");
                        atualDb1 = "";
                        quantComp = 0;
                       }else{
                             cout << "\nNenhum registro com o nome '" << myDb << "' foi encontrado!\n";      
                       }
                  } 
                  for(int i = 0; i < 20; i++){
                      search[i] = -1;
                      search2[i] = -1;
                  }
              }else{
                    if(comm == "ALL_FIELD_NO_BASE"){
                          if(val1 == 0)
                                cout << "\n----------------------------------------------------\n";
                          
                          
                    	  int i = 0, j = 0;
                    	  bool loop = true;
                    	  while(loop){
                               printf(">[%d] - ", quantComp);  
                               for(j = 0; data.field[i][j] != -1; j++){
                                    printf("%c", data.field[i][j]); 
                               }
                               i = i + 1;
                               quantComp++;
                               j = 0;
                               if(data.field[i][j] == -1)
                                     loop = false;
                              
                               printf("\n");           
                           }
                           if(val1 == (val2-1)){
                                    cout << "\n----------------------------------------------------\n";
                                    cout << "CAMPOS ENCONTRADOS : " << (quantComp-1) << endl;
                                    quantComp = 0;
                           }
                    }else{
                          if(cont(comm, "ALL_FIELD_IN_BASE")){
                                  string sub = comm.substr(17, comm.length());
                                  string db = sub.substr(sub.find(">")+1, sub.length());
							      string tb = comm.substr(18, sub.find(">")-1);
                                  string atualDb;
                                  string atualTb;
                                  for(int i = 0; i < 20; i++)
                                          search[i] = (data.database[i] != -1) ? data.database[i] : 0;
                                  
                                  for(int i = 0; i < 20; i++)
                                          search2[i] = (data.table[i] != -1) ? data.table[i] : 0;
                                          
                                  atualDb = search;
                                  atualTb = search2;
                                  if(atualTb == tb){ 
                                       if(atualDb == db){
                                           conc1 << ">" << search << "\n" << "\t>" << search2;
                                           cout << "\n----------------------------------------------------\n";
                                           cout << conc1.str() << endl;
                                           int i = 0, j = 0;
                                    	   bool loop = true;
                                    	   while(loop){
                                               printf("\t\t>[%d] - ", i);  
                                               for(j = 0; data.field[i][j] != -1; j++){
                                                    printf("%c", data.field[i][j]); 
                                               }
                                               i = i + 1;
                                               quantComp++;
                                               j = 0;
                                               if(data.field[i][j] == -1)
                                                     loop = false;
                                              
                                               printf("\n");           
                                           }
                                           cout << "----------------------------------------------------\n";
                                           cout << "CAMPOS ENCONTRADOS NA TABELA '" << atualTb << "' : " << quantComp << endl;
                                           conc1.str("");
                                           quantComp = 0;
                                       }     
                                  }
                                  for(int i = 0; i < 20; i++){
                                      search[i] = -1;
                                      search2[i] = -1;
                                  } 
							}else{
                                if(comm == "ALL"){
									 for(int i = 0; i < 20; i++)
										search[i] = (data.database[i] != -1) ? data.database[i] : 0;
                  
									for(int i = 0; i < 20; i++)
										search2[i] = (data.table[i] != -1) ? data.table[i] : 0;
										
                                    
					                  tableQuant++;
                                      conc1 << ">" << search << endl;
									  conc2 << "\t>" << search2 << endl;
                                      conc2 << "\n\t\t>";
                                	  int i = 0, j = 0;
                                	  bool loop = true;
                                	  while(loop){
                                           if(i > 0)
                                                conc2 << "\t\t>[" << i << "] - ";
                                           else
                                                conc2 << "[" << i <<"] - ";
                                                
                                           for(j = 0; j < 20; j++){
                                                search3[j] =  (data.field[i][j] != -1) ? (char) data.field[i][j] : 0; 
                                           }
                                            conc2 << search3 << endl;     
                                           i = i + 1;
                                           j = 0;
                                           if(data.field[i][j] == -1)
                                                 loop = false;
                                           
                                           fieldQuant++;
                                      }
									  
									  atualDb1 = search;
									  if(!cont(conc3.str(), atualDb1)){
									       conc3 << search << "(" << num << ")";
										   conc4[num] << conc1.str() << conc2.str();
										   conc2.str("");
										   conc1.str("");
										   num++;
									  }else{
										  string subSt = conc3.str().substr(conc3.str().find(atualDb1)+(atualDb1.length()+1));
										  subSt.replace(subSt.find(")"), 1, "");
										 // cout << subSt << endl;
										  char number[1];
										  for(int i = 0; i < subSt.length(); i++)
										        number[i] = subSt[i];
										        
										  int index = atoi(number);
										  conc4[index] << conc2.str();
										  conc2.str("");
										  conc1.str("");
									  }
                                
                                               
                                       if(val1 == (val2-1)){
                                               baseQuant = num;
                                               cout << "\n----------------------------------------------------\n";
                                               for(int i = 0; i < num; i++){
                                                     string all = conc4[i].str();
                                                     cout << all;
                                                     conc4[i].str("");
                                               }
                                               cout << "----------------------------------------------------\n";
                                               cout << "BASES ENCONTRADAS : " << baseQuant << endl;
                                               cout << "TABELAS ENCONTRADAS : " << tableQuant << endl;
                                               cout << "CAMPOS ENCONTRADOS : " << fieldQuant << endl;
                                               conc1.str(""); baseQuant = 0;
                                               conc2.str(""); tableQuant = 0;
                                               conc3.str(""); fieldQuant = 0;
                                               num = 0;
                                       }
                                       
                                              
                                       for(int i = 0; i < 20; i++){
                                               search[i] = -1; 
                                               search2[i] = -1;
                                               search3[i] = -1;
                                       } 
                                }else{
                                     if(comm == "FINAL_DATA"){
                                          if(val1 == (val2-1)){
                                              cout << "\n----------------------------------------------------\n";
                                              printf(">");
                                              for(int i = 0; i < 20; i++){ 
                                                      printf("%c", data.database[i]);
                                                      search[i] = (data.database[i] != -1) ? data.database[i] : 0;
                                              }
                                              conc2 << ">" << search;
                                              if(!cont(conc1.str(), conc2.str()))       
                                                   conc1 << ">" << search << "\n";
                                                   
                                              conc2.str("");
                                              printf("\n\t>");
                                              for(int i = 0; i < 20; i++)
                                                      printf("%c", data.table[i]); 
                                                  
                                              printf("\n\t\t>");
                                        	  int i = 0, j = 0;
                                        	  bool loop = true;
                                        	  while(loop){
                                                   if(i > 0)
                                                        printf("\t\t>[%d] - ", i);
                                                   else
                                                        printf("[%d] - ", i);
                                                        
                                                   for(j = 0; data.field[i][j] != -1; j++){
                                                        printf("%c", data.field[i][j]); 
                                                   }
                                                   i = i + 1;
                                                   j = 0;
                                                   if(data.field[i][j] == -1)
                                                         loop = false;
                                                         
                                                   printf("\n");
                                              }
                                               cout << "----------------------------------------------------\n";
                                               for(int i = 0; i < 20; i++)
                                                       search[i] = -1; 
                                               }
                                    }else{
										if(cont(comm, "SEARCH_TO_ADD")){
											string sub = comm.substr(13, comm.length());
											string tb = comm.substr(14, sub.find(">")-1);
											string subDb = sub.substr(sub.find(">")+1, sub.length());
											string db = subDb.substr(0, subDb.find("["));
											string values = subDb.substr(subDb.find("["), subDb.find("]")+1);
											string atualDb;
											string atualTb;
											string fields;
											stringstream value;
											int sizeFields = 0;
											
											for(int i = 0; i < 20; i++)
												search[i] = (data.database[i] != -1) ? data.database[i] : 0;
                                  
											for(int i = 0; i < 20; i++)
												search2[i] = (data.table[i] != -1) ? data.table[i] : 0;
											
										
											
											atualDb = search;
											atualTb = search2;
											atualDb = atualDb.substr(0, db.length());
											atualTb = atualTb.substr(0, tb.length());
											
											if(atualTb == tb){ 
											   if(atualDb == db){
												  
													for(int i = 0; i < values.length(); i++)
														if(values[i] == ',')
															++sizeFields;
													
													int k = 0;
													string val[sizeFields+1];
													values = values.replace(0, 1, "");
													for(int i = 0; i < values.length(); i++){
														if(values[i] != ',' && values[i] != ']'){
															if(values[i] != ' ')
																value << values[i];
															
														}else{
															val[k] = value.str();
															value.str("");
															++k;
														}
														
													}
													
											
												   int i = 0, j = 0;
												   bool loop = true;
												   conc1 << "\n" << tb << " registers(){\n";
												   conc1 << "\t" << tb << " reg;\n";
												    while(loop){
													    for(j = 0; j < 20; j++){
															search3[j] =  (data.field[i][j] != -1) ? (char) data.field[i][j] : 0;
														}
														conc3 << search3;
														fields = conc3.str();
														conc3.str("");
														
														conc2 << "\t" << fields << ";\n";
														
														string delType = fields.substr(0, fields.find(" ")+1);
														string element = fields.replace(0, delType.length(), "");
														
														
														bool numeric = true;
														string val1;
														val1 = val[i];
														for(int a = 0; a < val[i].length(); a++){
															if(!isNumeric(val1[a])){
																numeric = false;
																break;
															}
														}
														
														
														if(numeric){
															conc1 << "\treg." << element << " = ";
															conc1 << val[i] << ";\n";
														}else{
															conc1 << "\tchar *c" << i << " = ";
															conc1 << '"' << val[i] << '"' << ";\n"; //ponteiro do campo
															conc1 << "\treg." << element << " = ";  
															conc1 << "c" << i << ";\n"; //atribuir ponteiro a estrutura
														}
														
														floatPoint = 0;
														cout << conc3.str() << endl;
													    i = i + 1;
													    fieldQuant++;
													    j = 0;
													    if(data.field[i][j] == -1)
															loop = false;
													          
												    }
												   
												   conc1 << "\treturn reg;\n" << "}\n";
												   stringstream function, object, returned, obj, index;
												   string dataFields;
												   function << "\n" << tb << " " << "registers(){\n";
												   object << "\t" << tb << " reg;\n";
												   obj << "reg.";
												   returned << "\treturn reg;\n" << "}\n";
												   
												   dataFields = conc1.str().replace(0, function.str().length(), "");
												   dataFields = dataFields.replace(0, object.str().length(), "");
												   for(int i = 0; i < fieldQuant; i++){
														index << "\t>[" << i << "] - ";
														dataFields = dataFields.replace(dataFields.find(obj.str()), obj.str().length(), index.str());
														dataFields = dataFields.replace(dataFields.find(";"), 1, "");
														index.str("");
												   }
												   dataFields = dataFields.replace(dataFields.find(returned.str()), returned.str().length(), "");
												   function.str("");
												   object.str("");
												   returned.str("");
												   obj.str("");
												   
												   cout << "----------------------------------------------------\n";
												   cout << ">" << db << endl;
												   cout << "\t>" << tb << endl;
												   cout << dataFields << endl;
												   cout << "----------------------------------------------------\n";
												   
												    nArray = fieldQuant;
												    fieldQuant = 0;
											   }     
											}
											for(int i = 0; i < 20; i++){
												search[i] = -1;
												search2[i] = -1;
											} 
								  
										}
									} 
                                }
   
							}
                            
                    }
                   
				}
    
			} 
    }
}

void Insert(int size, char *dbFile, int dataLength, int tableLength, int b1[], int t1[])
{
        
         DataBase data[size];
         for(int i = 0; i < size; i++)
         {
           data[i] = gerar_Reg(dataLength, tableLength, b1, t1);      
         }
     
     
     FILE *arquivo;
     if((arquivo = fopen(dbFile, "wb")) == NULL)
     {
           printf("\nErro ao salvar os dados!\n");
           return;
     }
     fwrite(data, sizeof(DataBase), size, arquivo);
     fclose(arquivo);
     
     DataQuant quantity;
     quantity = ReadQuant();
     SaveQuant(quantity.atual+1);
     
     printf("\nRegistrando valores...\n");
}


void Select(int size, char *dbFile, string commands)
{

       FILE *arquivo;
       if((arquivo = fopen(dbFile, "rb")) == NULL){
            printf("\nNenhum registro foi encontrado!\n");
            return;
       } 
       
       DataBase data[size];
       int i = 0;
       while(!feof(arquivo)){
               fread(&data[i], sizeof(DataBase), 1, arquivo);
               i++;
       }
     
	   
      if(i > 0)
       if(commands == "FINAL_DATA")
            printf("\nOs seguintes dados foram registrados :");
       else
		   if(cont(commands, "SEARCH_TO_ADD"))
				printf("\nOs seguintes dados foram adicionados :");
		   else
				printf("\nOs seguintes dados foram encontrados :");
       
       int tam = i-1;
       for(int j = 0; j < tam; j++)
               exibir_Registros(data[j], commands, j, tam); 
               
       
       fclose(arquivo);
}

//Criar arquivo de banco de dados
void ConstDB(string str)
{
      char var[str.length()];
      for(int i = 0; i < (str.length()); i++)
            var[i] = str[i];
      
      char* consts = var;
      strcat(consts, ".db");
      FILE *base;
      string file = FcharTstring(consts);
      if((base = fopen(consts, "wb")) == NULL){
           cout << "Erro ao criar o Banco '" << file.substr(0, file.length()-2) << "'" << endl;
           return;
      }     
      fclose(base);
      cout <<  file.substr(0, file.size()-2) << " Criado com sucesso!" << endl;
}

void CreateInsert(string table, string database, int action)
{
     
     string data2;
     stringstream func;
 
            
     FILE *file;
     file = fopen("Insert.cpp", "w");
 
     func << "#include <cstdlib>\n" << "#include <cstdio>\n" << "#include \"Structs.h\"\n\n";
	 if(action == 1){
		 func << registers << "\n";
	 }
     func << "void insertTable(){\n\n";
     func << "\tint size = 1;\n";
     func << "\t" << table;
     func << " insert[size];\n";
	 if(action == 1){
		func << "\tfor(int i = 0; i < size; i++)\n";
		func << "\t\tinsert[i] = registers();\n\n";
	 }
     func << "\tFILE *arquivo;\n\n";
     func << "\tif((arquivo = fopen(\"";
     func << database << "." << table;
     func << ".db";
     func << "\", \"wb\")) == NULL){\n";
     func << "\tprintf(\"\\nErro ao salvar os dados!\\n\");\n";
     func << "\treturn;\n";
     func << "\t}\n\n";
     func << "\tfwrite(insert, sizeof(";
     func << table;
     func << "), size, arquivo);\n";
     func << "\tfclose(arquivo);\n";
	 switch(action){
		 case 0: func << "\tprintf(\"\\nTabela '" << table << "' construida na base '" << database << "'!\\n\");\n";
				 func << "\tprintf(\"Codigo pxdb executado com 0 erros!\\n\");\n";
				 break;
		 case 1: func << "\tprintf(\"\\n Valores foram inseridos em '" << nArray << "' campos respectivamente na tabela '";
				 func << table << "' na base '" << database << "'!\\n\");\n";
				 func << "\tprintf(\"Codigo pxdb executado com 0 erros!\\n\");\n";
				 break;
	 }
     func << "}\n\n";
     func << "int main(void){\n" << "\t insertTable();\n" << "\t return 0;\n" << "}\n";    
    
    data2 = func.str();
    char data1[data2.length()];
    char* data3;
    for(int i = 0; i < (data2.length()+1); i++)
             data1[i] = data2[i];
    
     data3 = data1;
     fprintf(file, "%s", data3);
     fclose(file);
}

void CreateStruct(string table, string fi, string fields[], int quantFields, int tableLength, int action){
		  FILE *file;
          char var[tableLength];
		  char data[quantFields];
          for(int i = 0; i < (tableLength+1); i++)
               var[i] = table[i];
          
          char* structs = var;
          file = fopen("Structs.h", "w");
          fprintf(file, "struct %s {", structs);
          string field;
		  
		  if(action == 0){
			  for(int j = 0; j < quantFields; j++){
				   field = fields[j];
				   fie2[j] = field;
					
				   for(int i = 0; i < (field.length()+1); i++){
						data[i] = field[i];
						fie1[j][i] = field[i];
				   }
					fprintf(file, "\n\t%s;", data); 
			  }
				   char *end = "};";
				   fprintf(file, "\n%s\n", end);
		  }else{
			  if(action == 1){
					for(int i = 0; i < quantFields+1; i++){
						data[i] = fi[i];
					}
				  fprintf(file, "\n%s", data); 
				  char *end = "\n};";
				  fprintf(file, "%s\n", end);
			  }
		  }
          fclose(file);
}

void pxdbExecute()
{
       system("@ECHO OFF");
       system("g++.exe Insert.cpp -o Insert.exe -g3 -I C:\\Dev-Cpp\\lib\\gcc\\mingw32\\3.4.2\\include -I C:\\Dev-Cpp\\include\\c++\\3.4.2\\backward -I C:\\Dev-Cpp\\include\\c++\\3.4.2\\mingw32 -I C:\\Dev-Cpp\\include\\c++\\3.4.2 -I C:\\Dev-Cpp\\include -L C:\\Dev-Cpp\\lib -g3 ");
       system("echo Executando Pxdb...");
       system("Insert.exe");   
}

void pxdbCommand()
{
     bool sintax = false;
     DataQuant quantity;
     quantity = ReadQuant();
     cout << "Command >> ";
     getline(cin, command);
     if(cont(command, "CONST TABLE")){
          sintax = true;
          int quantFields = 0;
          string subCom = command.substr(12, command.length());
          database = subCom.substr(subCom.find("IN")+3, subCom.length());
          table = command.substr(12, (subCom.find("IN")-1));
          cout << "Size >> ";
          scanf("%d", &quantFields);
          string fields[quantFields];
          string temp;
		  nArray = quantFields;
          for(int s = -1; s < quantFields; s++){
                if(s == -1){
                    getline(cin, temp);
                }else{
                    cout << "field[" << s << "]: ";
                    getline(cin, temp);
                    if(cont(temp, "text "))
	                       temp.replace(temp.find("text"), 4, "char*");
	                       
                    fields[s] = temp;
                }
          }
         
          
          
          int b1[database.length()];
          for(int i = 0; i < (database.length()+1); i++)
               b1[i] = database[i];
          
          int t1[table.length()];
          for(int i = 0; i < (table.length()+1); i++)
               t1[i] = table[i];
			
		  CreateStruct(table, temp, fields, quantFields, table.length(), 0);
          CreateInsert(table, database, 0);
          Insert(1, "DataBase.db", database.length(), table.length(), b1, t1);
          pxdbExecute();
          quantity = ReadQuant();
          printf("FORAM ENCONTRADAS %d TABELAS REGISTRADAS!\n", quantity.atual); 
          Select(quantity.atual, "DataBase.db", "FINAL_DATA");
     }
         
     if(cont(command, "CONST DATABASE")){
          sintax = true;
          string database = command.substr(15, command.length());
          ConstDB(database);
     }
     
      
		if(cont(command, "SEARCH ALL")){
          sintax = true;
          if(cont(command, "SEARCH ALL DATABASE")) {
			 cout << "Pesquisando todas as bases de dados ..." << endl;
             Select(quantity.atual, "DataBase.db", "ALL_DATABASE");  
		  }else{
			 if((cont(command, "SEARCH ALL TABLE")) && (!cont(command, "IN"))){
				 cout << "Pesquisando todas as tabelas ..." << endl;
	             Select(quantity.atual, "DataBase.db", "ALL_TABLE_NO_BASE");
			 }else{
				 if((cont(command, "SEARCH ALL FIELD")) && (!cont(command, "IN"))){
					 cout << "Pesquisando todos os campos ..." << endl;
	                 Select(quantity.atual, "DataBase.db", "ALL_FIELD_NO_BASE");
				 }else{
					 if(cont(command, "SEARCH ALL TABLE IN")){
						string db = command.substr(20, command.length()); 
						cout << "Pesquisando todas as tabelas na base '" << db << "' ..." << endl;
                        stringstream dbConc;
                        dbConc << "ALL_TABLE_IN_BASE:" << db;
                        string theDb = dbConc.str();
                        dbConc.str("");
	                    Select(quantity.atual, "DataBase.db", theDb);
					 }else{
						 if(cont(command, "SEARCH ALL FIELD IN")){
							string sub = command.substr(20, command.length());
							string tb = command.substr(20, sub.find(">")-1);
							string db = sub.substr(sub.find(">")+2, sub.length());
							cout << "Pesquisando todos os campos na tabela '" << tb << "' e base '" << db << "' ..." << endl; 
                            stringstream dbConc;
                            dbConc << "ALL_FIELD_IN_BASE:" << tb << ">" << db;
                            string TbDb = dbConc.str();
                            dbConc.str("");
	                        Select(quantity.atual, "DataBase.db", TbDb);
						 }else{ 
                               if(command == "SEARCH ALL")
	                               Select(quantity.atual, "DataBase.db", "ALL"); 
                               else
                                   cout << "A sintaxe do comando esta incorreta!" << endl;    
                         }
					 }
				 }
			 }
		  }
		}
     
	    if(cont(command, "ADD")){
			string subValues = command.substr(4, command.length());
			string subData = command.substr(command.find("IN")+3, command.length());
			
			string values = command.substr(4, subValues.find("]")+1);
			string tb = subData.substr(0, subData.find(">")-1);
			string db = subData.substr(subData.find(">")+2, subData.length());
			
			stringstream concToAdd;
			concToAdd << "SEARCH_TO_ADD:" << tb << ">" << db << values;
			string searchToAdd = concToAdd.str();
			
			Select(quantity.atual, "DataBase.db", searchToAdd);
			
			int sizeStruct = conc2.str().length();
			string dataStruct[sizeStruct];
			string data = conc2.str();
			registers = conc1.str();
			
			CreateStruct(tb, data, dataStruct, sizeStruct, tb.length(), 1);
			CreateInsert(tb, db, 1);
			
			pxdbExecute();
			
			nArray = 0;
			conc1.str(""); 
			conc2.str("");
			floatPoint = 0;
			concToAdd.str("");
			sintax = true;
		}
		
     if(!sintax)
         cout << "A sintaxe do comando '" << command << "' esta incorreta!" << endl;
         
     if(cont(command, "EXIT")){
          ext = true;                 
     }
     
}

int main(void)
{
  while(!ext)
    {
         pxdbCommand();
         if(!ext)
             system("PAUSE");
               
         system("CLS");     
    }
    
    printf("Saindo do pxdb!");
    return 0;    
}
