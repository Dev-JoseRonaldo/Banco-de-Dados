"use client";

import Header from "@/components/Header";

export default function HomeAluno() {
  const jobOffers = [
    { titulo: "Desenvolvedor Jr.", cargo: "Dev Frontend", descricao: "Vaga para React", salario: "R$ 5.000", empresa: "Tech Corp", dataAbertura: "30/01/2025" },
    { titulo: "Analista de Dados", cargo: "Data Analyst", descricao: "Vaga para análise de dados", salario: "R$ 6.000", empresa: "Data Inc", dataAbertura: "28/01/2025" },
  ];

  return (
    <div className="min-h-screen bg-[#f9fafb] text-black">
      <Header user="Aluno" />
      <div className="p-6 max-w-[1280px] mx-auto">
        <h2 className="text-2xl font-bold mb-4">Vagas Disponíveis</h2>
        <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
          {jobOffers.map((job, index) => (
            <div key={index} className="bg-white p-4 rounded-lg shadow-md">
              <h3 className="text-xl font-bold">{job.titulo}</h3>
              <p className="text-gray-700">{job.cargo}</p>
              <p className="text-sm">{job.descricao}</p>
              <p className="text-green-600 font-bold">{job.salario}</p>
              <p className="text-gray-500 text-sm">Empresa: {job.empresa}</p>
              <p className="text-gray-400 text-xs">Aberta em: {job.dataAbertura}</p>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}
