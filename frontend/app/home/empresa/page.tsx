"use client";

import Header from "@/components/Header";
import { useRouter } from "next/navigation";

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
    },
    {
      nome: "Maria Oliveira",
      idade: 22,
      curso: "Ciência da Computação",
      anoMatricula: 2020,
      mediaGeral: 9.0,
      endereco: "Avenida Central, 456, Centro",
    },
    {
      nome: "Carlos Souza",
      idade: 23,
      curso: "Sistemas de Informação",
      anoMatricula: 2019,
      mediaGeral: 7.8,
      endereco: "Travessa dos Andes, 789, Jardim Nova Era",
    },
    {
      nome: "Ana Costa",
      idade: 20,
      curso: "Análise e Desenvolvimento de Sistemas",
      anoMatricula: 2022,
      mediaGeral: 8.3,
      endereco: "Rua do Sol, 321, Bairro Alto",
    },
  ];
  
  return (
    <div className="min-h-screen bg-[#f9fafb] text-black">
      <Header user="Empresa" />
      <div className="p-6 max-w-[1280px] mx-auto">
        <h2 className="text-4xl font-bold mb-4">Alunos Disponíveis</h2>
        <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
          {students.map((student, index) => (
            <div key={index} className="bg-white p-6 rounded-xl shadow-md">
              <h3 className="text-2xl font-bold">{student.nome}</h3>
              <p className="text-gray-700">Curso: {student.curso}</p>
              <p className="text-gray-600">Idade: {student.idade}</p>
              <p className="text-gray-600">Ano de Matrícula: {student.anoMatricula}</p>
              <p className="text-gray-600">Endereço: {student.endereco}</p>
              <p className="font-semibold text-green-600">Média Geral: {student.mediaGeral}</p>
            </div>
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
