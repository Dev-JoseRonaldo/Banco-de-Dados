"use client";

export default function Documentation() {
  return (
    <div className="min-h-screen bg-[#f9fafb] text-black">
      <header className="bg-primary text-white p-4 text-center text-xl font-bold">
        LkCIn - Documentação
      </header>

      <div className="p-6 max-w-[1280px] mx-auto space-y-6">
        {/* Descrição */}
        <section className="bg-white p-6 rounded-lg shadow-md">
          <h2 className="text-2xl font-bold mb-4">Descrição</h2>
          <p>
          LkCIn (Linkêcin) é um projeto desenvolvido inicialmente na disciplina de Banco de Dados (2024.1) e posteriormente aprimorado na disciplina de Estruturas de Dados Orientadas a Objetos (2024.2), ambas do curso de Sistemas de Informação da Universidade Federal de Pernambuco (UFPE). O objetivo do projeto é desenvolver uma plataforma de recrutamento que conecta alunos e ex-alunos do Centro de Informática (CIn) ao mercado de trabalho, permitindo candidaturas a vagas, indicações por parte de professores e ex-alunos, além de possibilitar que empresas encontrem talentos qualificados.
          </p>
        </section>

        {/* Imagens */}
        <section className="bg-white p-6 rounded-lg shadow-md">
          <h2 className="text-2xl font-bold mb-4">Imagens</h2>
          <div className="grid grid-cols-1 md:grid-cols-1 lg:grid-cols-2   gap-4">
            {[...Array(10)].map((_, index) => (
              <img
                key={index}
                src={`https://res.cloudinary.com/devjoseronaldo/image/upload/v1738340596/EDOO/${["ebr4wmmw3wonj4tabgop", "luiefronj46t3bea2ijk", "wcuabqcdzqdd2n8x0vcr", "xakekg7vczdhefzsxcmq", "oj8tj799rwvasnhczrak", "aqchr8txxsmecdzh5f9q", "zzskskpoksub4mwgvshu", "xpc1hy2fpftsiajx8vvz", "tcjvggduoahzrsfq64fq", "us6iw51gnkzmamvqa6ax"][index]}.png`}
                alt={`Imagem ${index + 1}`}
                className="w-full h-auto rounded-lg shadow"
              />
            ))}
          </div>
        </section>

        {/* Demonstração */}
        <section className="bg-white p-6 rounded-lg shadow-md">
          <h2 className="text-2xl font-bold mb-4">Demonstração</h2>
          <div className="relative w-full h-0 pb-[56.25%]">
            <iframe
              className="absolute top-0 left-0 w-full h-full rounded-lg"
              src="https://www.youtube.com/embed/agQKUjSTnNM"
              title="Demonstração do LkCIn"
              allowFullScreen
            ></iframe>
          </div>
        </section>

        {/* Link do projeto */}
        <section className="bg-white p-6 rounded-lg shadow-md">
          <h2 className="text-2xl font-bold mb-4">Link do Projeto</h2>
          <a
            href="https://github.com/Dev-JoseRonaldo/LKCIn"
            target="_blank"
            rel="noopener noreferrer"
            className="text-blue-500 underline"
          >
            Repositório no GitHub
          </a>
        </section>

        {/* Contatos da equipe */}
        <section className="bg-white p-6 rounded-lg shadow-md">
          <h2 className="text-2xl font-bold mb-4">Equipe</h2>
          <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-2 gap-4">
            {[ 
              { name: "Luiz Henrique", github: "luiz-linkezio", linkedin: "lhbas" },
              { name: "José Ronaldo", github: "Dev-JoseRonaldo", linkedin: "devjoseronaldo" },
              { name: "Letícia Leitão", github: "leticialevleitao", linkedin: "leticialevleitao" },
              { name: "Cauê Marinho", github: "Cawezinn", linkedin: "cau%C3%AAsouza" },
            ].map((member, index) => (
              <div key={index} className="flex flex-col items-center text-center p-4 border rounded-lg shadow">
                <img
                  src={`https://github.com/${member.github}.png`}
                  alt={member.name}
                  className="w-24 h-24 rounded-full mb-2"
                />
                <p className="font-semibold">{member.name}</p>
                <a
                  href={`https://github.com/${member.github}`}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="text-blue-500 text-sm"
                >
                  GitHub
                </a>
                <a
                  href={`https://www.linkedin.com/in/${member.linkedin}/`}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="text-blue-500 text-sm"
                >
                  LinkedIn
                </a>
              </div>
            ))}
          </div>
        </section>
      </div>
    </div>
  );
}
