CREATE DATABASE mercado;
# id_cliente, nome, endereco, cidade, cep, uf, cnpj, ie

CREATE TABLE clientes (
id int NOT NULL,
nome varchar(30),
endereco varchar(90), 
cidade varchar(60),
cep varchar(8) NOT NULL,
uf char(2), 
cnpj varchar(16) NOT NULL UNIQUE,
ie varchar(4),
PRIMARY key (id)	
);
# id_vendedor, nome, salario, comissao
CREATE TABLE vendedores (
id int NOT NULL,
nome varchar(30),
salario DECIMAL(7,2),
comissao DECIMAL(7,2),
PRIMARY key (id)
);
# id, prazoEntrega, id_cliente, id_vendedor
CREATE TABLE pedidos (
id int NOT NULL,
prazoEntrega datetime,
PRIMARY key (id),
FOREIGN key (id_cliente) REFERENCES clientes(id),
FOREIGN key (id_vendedor) REFERENCES vendedores(id)
);
# id, unidade, descricao, valor_unitario
CREATE TABLE produtos (
id int NOT NULL,
unidade int(2),
descricao varchar(120),
valor_unitario DECIMAL(7,2),
PRIMARY key (id)
);
# id, id_produto, quantidade
CREATE TABLE intens_pedidos(
id int NOT NULL,
FOREIGN key (id_produto) REFERENCES produtos(id),
quantidade int(3),
PRIMARY key (id)
);