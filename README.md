# LKCIn

![Imagem 1](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340596/EDOO/ebr4wmmw3wonj4tabgop.png)
<br><br>
![Imagem 2](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340597/EDOO/wcuabqcdzqdd2n8x0vcr.png)
<br><br>
![Imagem 3](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340597/EDOO/xakekg7vczdhefzsxcmq.png)
<br><br>
![Imagem 4](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340596/EDOO/luiefronj46t3bea2ijk.png)
<br><br>
![Imagem 5](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340597/EDOO/oj8tj799rwvasnhczrak.png)
<br><br>
![Imagem 6](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340597/EDOO/aqchr8txxsmecdzh5f9q.png)
<br><br>
![Imagem 7](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340597/EDOO/zzskskpoksub4mwgvshu.png)
<br><br>
![Imagem 8](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340597/EDOO/xpc1hy2fpftsiajx8vvz.png)
<br><br>
![Imagem 9](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340597/EDOO/tcjvggduoahzrsfq64fq.png)
<br><br>
![Imagem 10](https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340597/EDOO/us6iw51gnkzmamvqa6ax.png)





## 💻 Projeto
Projeto da disciplina ***Banco de Dados***, da graduação em [Sistemas de Informação (SI)](https://portal.cin.ufpe.br/graduacao/sistemas-de-informacao/) do [Centro de Informática (CIN)](https://portal.cin.ufpe.br/) da [Universidade Federal de Pernambuco (UFPE)](https://www.ufpe.br/), cursada em no letivo 2024.1
<br>

O projeto consiste na modelagem do banco de dados de uma plataforma que conecta estudantes graduados do CIn ao seu primeiro emprego (categoria/função) após a graduação. Ela facilita a conexão entre empresas e alunos do CIn, bem como a indicação de alunos por professores e ex-alunos. oferecendo um espaço onde empresas podem encontrar talentos qualificados no centro de informática para preencher suas vagas. Além disso, a plataforma permite que professores e ex-alunos façam indicações de estudantes, aumentando as chances de sucesso na colocação profissional. Professores podem recomendar alunos que se destacaram academicamente, enquanto ex-alunos podem compartilhar oportunidades e suas experiências no mercado de trabalho, criando uma rede de apoio robusta. 

<br>

## Introdução
O mini-mundo consiste em uma plataforma de recrutamento que conecta estudantes, que estão na graduação ou já foram graduados, do Cin ao mercado de trabalho. Na plataforma, os alunos/ex-alunos podem se candidatar a diversas vagas oferecidas por diversas empresas. Ademais, pode haver indicação por parte das entidades para reforçar as candidaturas registradas.

## 🖊️ Requisitos
As funcionalidades do sistema consistem na possibilidade de um aluno fazer uma candidatura em uma ou mais vagas publicadas por uma empresa e na possibilidade de uma pessoa qualquer conseguir indicar um aluno/ex-aluno para uma vaga, quando o mesmo tiver realizado sua candidatura nessa mesma vaga.

## 🧬 Elementos do Modelo ER

### Entidades
- **Pessoa** - Entidade pai que participa de uma herança sobreposta total
- **Aluno** - Especialização de pessoa
- **Professor** -  Especialização de pessoa
- **Vínculo** - É uma entidade fraca pois está em um relacionamento 1:N onde pode ser identificado unicamente pela chave primária da entidade “Aluno” juntamente com seu discriminador (Matrícula).
- **Indicação** - É uma entidade fraca pois está em um relacionamento 1:N onde pode ser identificado unicamente pela chave primária da entidade “Candidatura” juntamente com os discriminadores do relacionamento identificador “Recebe” (data e hora)
- **Empresa** - representa as empresas cadastradas no sistema
- **Vaga** - É uma entidade fraca pois está em um relacionamento 1:N onde pode ser identificado unicamente pela chave primária da entidade “Empresa” juntamente com os discriminadores do relacionamento identificador “Divulga” (data e hora)
- **Currículo** - É uma entidade fraca pois está em um relacionamento 1:1 onde pode ser identificado unicamente pela chave primária da entidade “Pessoa” e por ter uma cardinalidade 1:1 não é necessário discriminadores para identificá-lo únicamente, apenas a chave primária da entidade “Pessoa” já faz essa identificação corretamente.
Candidatura - Entidade associativa usada para conectar o relacionamento “candidata” (aluno candidato a vaga), ao relacionamento recebe (candidatura recebe indicação)

### 🧱 Atributos
- A entidade “Pessoa” tem os atributos: Idade, Email, Telefones(multivalorado), Data Nascimento, CPF(identificador), Nome, Sexo, RG, Endereço(Composto - Bairro, Rua, CEP, Cidade).
- A entidade “Professor” tem os atributos: Tipo, Salário, Disciplinas(multivalorado), e todos os atributos de Pessoa, pois herda-os.
- A entidade “Aluno” possui todos os atributos de Pessoa, pois herda-os.
- A entidade “Vínculo” possui os atributos: Média geral do aluno, Matrícula(Identificador), Histórico Escolar, Situação Acadêmica, Curso, Semestre Entrada. 
- A entidade associativa “Candidatura” possui os atributos: Data e Status.
- A entidade “Empresa” possui os atributos: Nome, CNPJ(Identificador), Website, Endereço(Composto - Bairro, Rua, CEP, Cidade), Telefones(Multivalorado), Email. 
- A entidade “Currículo” possui os atributos: URL, Formações, Experiências, Idiomas, Habilidades, Certificações, Publicações(exceto o atributo URL, todos os demais apresentam-se como multivalorados).
- A entidade “Indicação” possui o atributo: Observações.
- A entidade “Vaga” possui os atributos: Descrição; Requisitos(multivalorado); Benefícios(multivalorado).
- A entidade “Candidatura” possui os atributos: Data; Status.


### 😏 Relacionamentos
- Relacionamento “**Tem**”, entre as entidades “Aluno” e “Vínculo”. Um aluno pode ter muitos vínculos e um vínculo só pode estar associado a um aluno. É um relacionamento identificador da entidade fraca “Vínculo”. Além disso, Aluno e Vínculo tem participação total no relacionamento, ou seja, um Aluno precisa ter um Vínculo para ser cadastrado no sistema, e um Vínculo só existe associado a um aluno.
- Relacionamento “**Faz**”, entre as entidades “Aluno”, “Pessoa” e “Indicação". É um relacionamento ternário onde uma instância da entidade “pessoa” associada a uma instância da entidade “aluno” pode fazer muitas indicações da mesma. Uma indicação feita por um professor só pode estar associada a um aluno. E uma indicação de um aluno pode ser feita por muitos professores.
- Relacionamento “**Recebe**”, entre as entidades “Candidatura”(entidade associativa) e “Indicação”. Uma Candidatura pode receber muitas Indicações e uma indicação tem que ser feita direcionada a uma candidatura. “Recebe” é um relacionamento identificador onde seus discriminadores identificam a entidade “Indicação”. Além disso, a entidade Candidatura tem uma participação parcial no relacionamento, ou seja, uma candidatura pode existir sem indicações.
- Relacionamento “**Candidatura**”, entre as entidades Aluno e Vaga. Um alunos podem se candidatar em muitas vagas publicadas. E uma Vaga pode receber candidaturas de muitos Alunos. Além disso, Aluno e Vaga tem parcial total no relacionamento.
- Relacionamento “**Divulga**”, entre as entidades Empresa e Vaga. Uma empresa pode publicar muitas Vagas e uma vaga só pode estar associada a uma empresa.  Vaga tem participação total no relacionamento e Empresa tem participação parcial no relacionamento. Ou seja, uma Vaga precisa está associada a uma Empresa para existir, diferente de Empresa que não precisa está associada a uma Vaga para existir.
- Relacionamento “**Tem**” entre as entidades Pessoa e Currículo. Uma instância de Pessoa pode ter apenas um Currículo, e um Currículo pertence a apenas uma Pessoa. Currículo tem participação total no relacionamento e pessoa tem participação parcial no relacionamento. Ou seja, um currículo precisa está associado a uma pessoa para existir, diferente de pessoa que não precisa está associado a um currículo para existir.

### 📑 Regras de negócio
- Uma pessoa pode assumir o papel de aluno e professor ao mesmo tempo
- Um aluno pode ter apenas um currículo cadastrado
- No sistema, só poderão ser cadastrados professores, alunos e ex-alunos
- Qualquer pessoa cadastrada no sistema pode indicar um aluno ou ex-aluno em candidaturas
- Um professor não pode ser indicado
- Um aluno pode ter vários vínculos
- Uma empresa pode divulgar inúmeras vagas no sistema
- Um aluno pode se candidatar para inúmeras vagas, inclusive na mesma empresa
- As vagas têm número ilimitado de candidaturas
- Um aluno pode realizar candidaturas sem possuir indicações
- Cada candidatura pode ter uma quantidade ilimitada de indicações, essas indicações podem ser feitas por qualquer pessoa cadastrada no sistema
- Cada indicação só pode ser direcionada para uma pessoa(aluno ou ex-aluno)
- Um aluno pode receber várias indicações, de várias pessoas diferentes
- O vínculo com a instituição de ensino só é considerado após o aluno realizar sua matrícula
- Uma indicação só pode ser feita se direcionada a uma candidatura
- Não existe vaga compartilhada entre empresas, uma vaga pertence a apenas uma empresa
- Um indicador só poderá indicar um aluno por vaga


## 💼 Equipe
<br>

| [<img src="https://github.com/luiz-linkezio.png" width=115><br><sub>Luiz Henrique</sub><br>](https://github.com/luiz-linkezio) <sub>Desenvolvedor</sub><br> <sub>[Linkedin](https://www.linkedin.com/in/lhbas/)</sub><br> | [<img src="https://github.com/dev-joseronaldo.png" width=115><br><sub>José Ronaldo</sub><br>](https://github.com/Dev-JoseRonaldo) <sub>Desenvolvedor</sub><br> <sub>[Linkedin](https://www.linkedin.com/in/devjoseronaldo/)</sub><br> | [<img src="https://github.com/leticialevleitao.png" width=115><br><sub>Letícia Leitão</sub><br>](https://github.com/leticialevleitao) <sub>Desenvolvedora</sub><br> <sub>[Linkedin](https://www.linkedin.com/in/leticialevleitao/)</sub><br> | [<img src="https://github.com/Cawezinn.png" width=115><br><sub>Cauê Marinho</sub><br>](https://github.com/Cawezinn) <sub>Desenvolvedor</sub><br> <sub>[Linkedin](https://www.linkedin.com/in/cau%C3%AAsouza/)</sub><br> | [<img src="https://github.com/joaopnolasco.png" width=115><br><sub>João Nolasco</sub><br>](https://github.com/joaopnolasco) <sub>Desenvolvedor</sub><br> <sub>[Linkedin](https://www.linkedin.com/in/joaonolasco10/)</sub><br> | [<img src="https://github.com/Ayrtonguimaraes.png" width=115><br><sub>Ayrton Farias</sub><br>](https://github.com/Ayrtonguimaraes) <sub>Desenvolvedor</sub><br> <sub>[Linkedin](https://www.linkedin.com/in/ayrton-farias-guimar%C3%A3es-93439b293/)</sub><br> | [<img src="https://github.com/vitoriabtriz.png" width=115><br><sub>Vitória Beatriz</sub><br>](https://github.com/vitoriabtriz) <sub>Desenvolvedora</sub><br> <sub>[Linkedin](https://www.linkedin.com/in/vitoriabtriz/)</sub><br> |
| :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
