interface JobCardProps {
  titulo: string;
  cargo: string;
  descricao: string;
  salario: string;
  empresa: string;
  dataAbertura: string;
}

export default function JobCard({ titulo, cargo, descricao, salario, empresa, dataAbertura }: JobCardProps) {
  return (
    <div className="bg-white p-6 rounded-xl shadow-md w-80">
      <h2 className="text-2xl font-bold">{titulo}</h2>
      <p className="text-gray-600">{cargo}</p>
      <p className="mt-2 text-gray-800">{descricao}</p>
      <p className="mt-2 font-semibold">Salário: R$ {salario}</p>
      <p className="text-gray-600">Empresa: {empresa}</p>
      <p className="text-gray-500 text-sm">Aberto em: {dataAbertura}</p>
    </div>
  );
}