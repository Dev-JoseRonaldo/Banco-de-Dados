"use client";

import { useState } from "react";
import Header from "@/components/Header";

interface Vaga {
  id: number;
  titulo: string;
  cargo: string;
  descricao: string;
  salario: string;
  empresa: string;
  dataAbertura: string;
}

export default function VagasPage() {
  const [vagas, setVagas] = useState<Vaga[]>([
    { id: 1, titulo: "Desenvolvedor Jr.", cargo: "Dev Frontend", descricao: "Vaga para React", salario: "R$ 5.000", empresa: "Tech Corp", dataAbertura: "30/01/2025" },
    { id: 2, titulo: "Analista de Dados", cargo: "Data Analyst", descricao: "Vaga para análise de dados", salario: "R$ 6.000", empresa: "Data Inc", dataAbertura: "28/01/2025" },
    { id: 3, titulo: "Desenvolvedor Jr.", cargo: "Dev Frontend", descricao: "Vaga para React", salario: "R$ 5.000", empresa: "Tech Corp", dataAbertura: "30/01/2025" },
    { id: 4, titulo: "Analista de Dados", cargo: "Data Analyst", descricao: "Vaga para análise de dados", salario: "R$ 6.000", empresa: "Data Inc", dataAbertura: "28/01/2025" },
  ]);
  
  const handleDelete = (id: number) => {
    setVagas(vagas.filter(vaga => vaga.id !== id));
  };

  const handleEdit = (id: number) => {
    alert(`Editar vaga ${id}`);
  };

  const handleAddVaga = () => {
    alert("Adicionar nova vaga");
  };

  return (
    <div className="min-h-screen bg-[#f9fafb] text-black">
      <Header user="Empresa" />
      <div className="p-6 max-w-[1280px] mx-auto">
        <div className="flex items-center justify-between mb-8">
          <h2 className="text-4xl font-bold mb-4">Gerenciar Vagas</h2>
          
          <button
            className="bg-primary text-white py-3 px-6 rounded-lg text-lg font-semibold shadow-md hover:bg-red-800 mb-6"
            onClick={handleAddVaga}
          >
            Cadastrar Nova Vaga
          </button>
        </div>
        
        <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
          {vagas.map((vaga) => (
            <div key={vaga.id} className="bg-white p-4 rounded-lg shadow-md">
              <h3 className="text-xl font-bold">{vaga.titulo}</h3>
              <p className="text-gray-700">{vaga.cargo}</p>
              <p className="text-sm">{vaga.descricao}</p>
              <p className="text-green-600 font-bold">{vaga.salario}</p>
              <p className="text-gray-500 text-sm">Empresa: {vaga.empresa}</p>
              <p className="text-gray-400 text-xs">Aberta em: {vaga.dataAbertura}</p>

              <div className="mt-4 flex justify-between">
                <button
                  className="bg-yellow-500 text-white py-2 px-4 rounded-lg"
                  onClick={() => handleEdit(vaga.id)}
                >
                  Editar
                </button>
                <button
                  className="bg-red-500 text-white py-2 px-4 rounded-lg"
                  onClick={() => handleDelete(vaga.id)}
                >
                  Deletar
                </button>
              </div>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}
