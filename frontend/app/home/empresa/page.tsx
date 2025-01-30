"use client";

import Header from "@/components/Header";
import { useRouter } from "next/navigation";
import StudentCard from "@/components/StudentCard";

export default function HomeEmpresa() {
  const router = useRouter();

  const students = [
    {
      nome: "João Silva",
      idade: 21,
      curso: "Engenharia de Software",
      anoMatricula: 2021,
      mediaGeral: 8.7,
      endereco: "Rua das Flores, 123, Bairro Primavera",
      email: "joao.silva@example.com",
      curriculo: "https://link-to-curriculo.com/joao-silva",
    },
    {
      nome: "Maria Oliveira",
      idade: 22,
      curso: "Ciência da Computação",
      anoMatricula: 2020,
      mediaGeral: 9.0,
      endereco: "Avenida Central, 456, Centro",
      email: "maria.oliveira@example.com",
      curriculo: "https://link-to-curriculo.com/maria-oliveira",
    },
    {
      nome: "Carlos Souza",
      idade: 23,
      curso: "Sistemas de Informação",
      anoMatricula: 2019,
      mediaGeral: 7.8,
      endereco: "Travessa dos Andes, 789, Jardim Nova Era",
      email: "carlos.souza@example.com",
      curriculo: "https://link-to-curriculo.com/carlos-souza",
    },
    {
      nome: "Ana Costa",
      idade: 20,
      curso: "Análise e Desenvolvimento de Sistemas",
      anoMatricula: 2022,
      mediaGeral: 8.3,
      endereco: "Rua do Sol, 321, Bairro Alto",
      email: "ana.costa@example.com",
      curriculo: "https://link-to-curriculo.com/ana-costa",
    },
  ];

  return (
    <div className="min-h-screen bg-[#f9fafb] text-black">
      <Header user="Empresa" />
      <div className="p-6 max-w-[1280px] mx-auto">
        <h2 className="text-4xl font-bold mb-4">Alunos Disponíveis</h2>
        <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
          {students.map((student, index) => (
            <StudentCard
              key={index}
              nome={student.nome}
              idade={student.idade}
              curso={student.curso}
              anoMatricula={student.anoMatricula}
              mediaGeral={student.mediaGeral}
              endereco={student.endereco}
              email={student.email}
              curriculo={student.curriculo}
            />
          ))}
        </div>
        <button
          className="mt-6 bg-primary text-white py-3 px-6 rounded-lg text-lg font-semibold shadow-md hover:bg-red-800"
          onClick={() => router.push("/home/empresa/vagas")}
        >
          Cadastrar Vaga
        </button>
      </div>
    </div>
  );
}
